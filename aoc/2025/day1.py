import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().strip().split("\n")

def one():
    d = 50
    ans = 0
    for g in G:
        n = nums(g)[0]
        if g[0] == 'L':
            d = (d - n) % 100
        else:
            d = (d + n) % 100
        if d == 0:
            ans += 1
    print(ans)

def two():
    d = 50
    ans = 0
    for g in G:
        n = nums(g)[0]
        for _ in range(1, n + 1):
            if g[0] == 'L':
                d -= 1
            else:
                d += 1
            d = d % 100
            if d == 0:
                ans += 1
    print(ans)

one()
two()
