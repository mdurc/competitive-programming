from collections import deque, defaultdict, Counter
import heapq
import re
import sys
from functools import cache
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

m = {}
def solve(s):
    if s in m: return m[s]

    if len(s) == 0:
        return 1
    else:
        result  = 0
        for o in opts:
            if s.startswith(o):
                result += solve(s[len(o):])
            m[s] = result

    return m[s]

@cache
def solve_cache(s):
    if len(s) == 0:
        return 1
    result  = 0
    for o in opts:
        if s.startswith(o):
            result += solve_cache(s[len(o):])
    return result

ans = 0
for t in towels:
    ans += solve_cache(t)
print(ans)
