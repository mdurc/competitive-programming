import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = [list(g) for g in open(0).read().strip().split("\n")]
rows, cols = len(G), len(G[0])

sr, sc = 0, 0
for i in range(rows):
    for j in range(cols):
        if G[i][j] == 'S':
            sr, sc = i, j

def one():
    ans = 0
    beams = [(sr, sc)]
    while beams:
        nxt = []
        for r, c in beams:
            if r+1 >= rows: continue
            if G[r+1][c] == '.' and (r+1, c) not in nxt:
                nxt.append((r+1, c))
            if G[r+1][c] == '^':
                ans += 1
                if c+1 < cols and (r+1,c+1) not in nxt:
                    nxt.append((r+1,c+1))
                if c-1 >= 0 and (r+1,c-1) not in nxt:
                    nxt.append((r+1,c-1))
        beams = nxt
    print(ans)

memo = {}
def solve(r, c):
    if c < 0 or c >= cols: return 0
    while r+1 < rows and G[r+1][c] == '.':
        r += 1
    if r+1 >= rows: return 0
    if (r,c) in memo:
        return memo[(r,c)]
    memo[(r,c)] = 1 + solve(r+1, c+1) + solve(r+1, c-1)
    return memo[(r,c)]


def two():
    print(1 + solve(sr, sc))

one()
two()
