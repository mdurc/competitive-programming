from collections import deque
import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().splitlines()
adj = {"out":[]}
for l in G:
    n, s = l.split(":")
    adj[n] = s.strip().split()

def one():
    seen = {"you":1}
    q = deque({"you"})
    while q:
        a = q.popleft()
        for b in adj[a]:
            if b in seen:
                seen[b] += seen[a]
                continue
            seen[b] = seen[a]
            q.append(b)
    print(seen["out"])

def two():
    seen = {"svr":[1, False, False]}
    q = deque({"svr"})
    while q:
        a = q.popleft()
        for b in adj[a]:
            if b in seen:
                seen[b] += seen[a]
                continue
            seen[b] = seen[a]
            if b == "dac": seen[b][1] = True
            if b == "fft": seen[b][2] = True
            q.append(b)
    print(seen["out"])

one()
two()
