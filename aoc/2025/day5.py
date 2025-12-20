import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

a, b = open(0).read().strip().split("\n\n")
fresh = [(int(i), int(j)) for i, j in [l.split("-") for l in a.split("\n")]]
avail = [int(i) for i in b.split("\n")]

def one():
    ans = 0
    for i in avail:
        for j, k in fresh:
            if i >= j and i <= k:
                ans += 1
                break
    print(ans)

def two():
    ans = 0
    fresh.sort()
    for i in range(len(fresh)):
        x, y = fresh[i]
        if i > 0 and x >= fresh[i-1][0] and x <= fresh[i-1][1]:
            x = fresh[i-1][1] + 1
        if y >= x:
            ans += y - x + 1
    print(ans)

one()
two()
