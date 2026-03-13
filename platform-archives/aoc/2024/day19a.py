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

opts, towels = open(0).read().strip().split("\n\n")

opts = opts.split(", ")
towels = towels.split("\n")

ans = 0
for t in towels:
    pq = deque([""])
    seen = set()
    while pq:
        s = pq.popleft()
        if s in seen: continue
        seen.add(s)
        if s == t:
            ans += 1
            break
        for o in opts:
            if s+o in seen: continue
            if t.startswith(s+o):
                pq.append(s+o)

print(ans)
