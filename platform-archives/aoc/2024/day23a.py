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

G = open(0).read().strip().split("\n")

edges = [l.strip().split('-') for l in G]

adj = defaultdict(set)

for i, j in edges:
    adj[i].add(j)
    adj[j].add(i)

seen = set()
for i in adj:
    for j in adj[i]:
        for k in adj[j]:
            if i != k and i in adj[k]:
                seen.add(tuple(sorted([i,j,k])))

ans = 0
for s in seen:
    ans += any(c.startswith("t") for c in s)
print(ans)
