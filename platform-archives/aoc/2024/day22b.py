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

ans = 0
seq_to_total = defaultdict(int)
for n in G:
    buyer = [n % 10]
    for _ in range(2000):
        n = step(n)
        buyer.append(n % 10)
    seen = set()
    for i in range(len(buyer) - 4):
        a, b, c, d, e = buyer[i:i+5]
        seq = (b-a, c-b, d-c, e-d)
        if seq in seen: continue
        seen.add(seq)
        seq_to_total[seq] += e
    ans += n

print(max(seq_to_total.values()))

