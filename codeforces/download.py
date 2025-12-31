#!/usr/bin/env python3
import http.server
import json
import re
import argparse
from pathlib import Path
from threading import Thread

PORT = 10043
RECEIVED = 0
TARGET_DIR = None
TARGET_COUNT = None

def sanitize_name(name: str) -> str:
    return re.sub(r'[^A-Za-z0-9]', '', name)

def parse_codeforces(data):
    url = data.get("url", "")
    name = data.get("name", "")
    m = re.search(r'/contest/(\d+)/problem/([A-Z0-9]+)', url)
    if not m:
        m = re.search(r'/problemset/problem/(\d+)/([A-Z0-9]+)', url)
        if not m:
            raise RuntimeError("Not a Codeforces contest url")
    contest_id = m.group(1)
    letter = m.group(2)
    title = name.split('.', 1)[-1].strip()
    title = sanitize_name(title)
    filename = f"{contest_id}{letter}-{title}.cpp"
    return filename

def write_cpp(filename: str, data: dict):
    # path = Path(filename)
    global TARGET_DIR
    path = TARGET_DIR / filename if TARGET_DIR else Path(filename)
    if path.exists():
        print(f"{filename} already exists, skipping.")
        return
    path.touch()
    print(f"Created {filename} from data:", data)

class CompetitiveCompanionHandler(http.server.BaseHTTPRequestHandler):
    def log_message(self, format, *args):
        super().log_message(format, *args)
    def do_POST(self):
        global RECEIVED
        length = int(self.headers["Content-Length"])
        data = json.loads(self.rfile.read(length))

        try:
            filename = parse_codeforces(data)
            write_cpp(filename, data)
            RECEIVED += 1
        except Exception as e:
            print("Error:", e)

        self.send_response(200)
        self.end_headers()

        if TARGET_COUNT is not None and RECEIVED >= TARGET_COUNT:
            print(f"Received {RECEIVED} problems, shutting down server.")
            Thread(target=self.server.shutdown).start()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="cp tool")
    parser.add_argument("-d", default=".", help="directory to put downloaded problems",)
    parser.add_argument("-n", nargs="?", type=int, default=None, help="number of expected problems to download")

    args = parser.parse_args()
    TARGET_DIR = Path(args.d).resolve()
    TARGET_DIR.mkdir(parents=True, exist_ok=True)
    TARGET_COUNT = args.n

    print(f"Download on contest page with CompetitiveCompanion")
    if TARGET_COUNT:
        print(f"Will stop after receiving {TARGET_COUNT} problems.")
    else:
        print("Press Ctrl+C to stop manually.")

    server = http.server.HTTPServer(("127.0.0.1", PORT), CompetitiveCompanionHandler)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nClosing server..")
        server.server_close()
