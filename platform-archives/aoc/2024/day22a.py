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

G = list(map(int,open(0).read().strip().split("\n")))

mod = 16777216
def step(n):
    n = ((n*64)^n)%mod
    n = ((n//32)^n)%mod
    n = ((n*2048)^n)%mod
    return n

#bit_mod = 2 ** 24 - 1
bit_mod = 0xFFFFFF
def bitwise_step(n):
    n = ((n << 6)^n) & bit_mod
    n = ((n >> 5)^n) & bit_mod
    n = ((n << 11)^n) & bit_mod
    return n

ans = 0
for n in G:
    for _ in range(2000):
        n = bitwise_step(n)
    ans += n

print(ans)

