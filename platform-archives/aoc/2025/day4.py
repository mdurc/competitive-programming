import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = [list(x) for x in open(0).read().strip().splitlines()]
rows = len(G)
cols = len(G[0])

def count(i, j):
    res = 0
    pos = [(-1,0), (-1,-1), (-1,1), (0,1), (0,-1), (1,0), (1,-1), (1,1)]
    for x, y in pos:
        ni = i + x
        nj = j + y
        if ni >= 0 and ni < cols and nj >= 0 and nj < rows:
            if G[ni][nj] == '@':
                res += 1
    return res < 4

def one():
    ans = 0
    for i in range(rows):
        for j in range(cols):
            if G[i][j] == '@':
                ans += count(i,j)
    print(ans)

def two():
    ans = 0
    while True:
        rem = []
        for i in range(rows):
            for j in range(cols):
                if G[i][j] == '@':
                    amt = count(i, j)
                    ans += amt
                    if amt == 1:
                        rem.append((i, j))
        if len(rem) == 0:
            break
        for i, j in rem:
            G[i][j] = '.'
    print(ans)

one()
two()
