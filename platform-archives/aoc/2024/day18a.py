from collections import deque, defaultdict, Counter
import heapq
import re
import sys
sys.setrecursionlimit(10**6)
DIRS = [(-1,0),(0,1),(1,0),(0,-1)] # up right down left
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

#grid = open(0).read().strip().split("\n")
#grid = [list(l) for l in grid]
#rows = len(grid)
#cols = len(grid[0])

G = open(0).read().strip()


rows = 71
cols = 71
#rows = 7
#cols = 7

mem = [nums(l) for l in G.split("\n")]
grid = [['.' for _ in range(cols)] for _ in range(rows)]

for i in range(1024):
    c,r = mem[i]
    grid[r][c] = "#"

pq = deque([(0,0,0)])
seen = set()
while pq:
    l, r, c = pq.popleft()
    if (r,c) in seen: continue
    seen.add((r,c))
    if (r,c) == (rows-1,cols-1):
        print(l)
        break
    for dr, dc in DIRS:
        nr, nc = r+dr, c+dc
        if (nr,nc) in seen: continue
        if 0<=nr<rows and 0<=nc<cols and grid[nr][nc]!="#":
            pq.append((l+1,nr,nc))


#for l in grid:
#    print(*l, sep="")
