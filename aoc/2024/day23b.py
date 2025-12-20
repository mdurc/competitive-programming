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

# keep track of all connected computers
def solve(node, req):
    key = tuple(sorted(req))
    if key in seen: return
    seen.add(key)

    for i in adj[node]:
        if i in req: continue
        if not req.issubset(adj[i]): continue
        solve(i, req | {i})

for i in adj:
    solve(i, {i})

print(",".join(sorted(max(seen, key=len))))

