from collections import deque, defaultdict, Counter
import heapq
import re
import sys
sys.setrecursionlimit(10**6)
DIRS = [(-1,0),(0,1),(1,0),(0,-1)] # up right down left
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

grid = open(0).read().strip().split("\n")
grid = [list(l) for l in grid]
rows = len(grid)
cols = len(grid[0])

#G = open(0).read().strip()

pr, pc = 0, 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "S":
            pr, pc = i, j

# problem states only one valid solution per grid
dists = [[-1]*cols for _ in range(rows)]
dists[pr][pc] = 0
while grid[pr][pc] != "E":
    for dr, dc in DIRS:
        nr, nc = pr+dr, pc+dc
        if not(0<=nr<rows and 0<=nc<cols): continue
        if grid[nr][nc] == "#": continue
        if dists[nr][nc] != -1: continue # already visited
        dists[nr][nc] = dists[pr][pc] + 1
        pr, pc = nr, nc


check = 0
count = 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "#": continue
        opts = [(i+2,j), (i+1,j+1), (i,j+2), (i-1,j+1),
                (i-2,j), (i-1,j-1), (i,j-2), (i+1,j-1)]
        for nr, nc in opts:
            if not(0<=nr<rows and 0<=nc<cols): continue
            if grid[nr][nc] == "#": continue
            if dists[i][j] - dists[nr][nc] >= 102: count += 1
print(count)
