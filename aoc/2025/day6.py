import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().strip().split("\n")

def one():
    ng = [nums(G[i]) for i in range(len(G)-1)]
    opts = [g for g in re.findall(r"\*|\+", G[-1])]
    ans = 0
    for i in range(len(ng[0])):
        s, m = 0, 1
        for j in range(len(ng)):
            m *= ng[j][i]
            s += ng[j][i]
        ans = ans + (s if opts[i] == '+' else m)
    print(ans)

def build(arr):
    res = 0
    for i in range(len(arr)):
        res += arr[i] * 10**(len(arr)-i-1)
    return res

def two():
    pos = []
    l = 0
    for r in range(len(G[-1])):
        if G[-1][r] != ' ' and r != l:
            pos.append((l,r-1))
            l = r
    pos.append((l, len(G[-1]) + 2))

    ans = 0
    for l, r in pos:
        s, m = 0, 1
        for j in range(l, r):
            arr = []
            for i in range(len(G) - 1):
                if G[i][j] == ' ':
                    continue
                arr.append(int(G[i][j]))
            res = build(arr)
            s += res
            m *= res
        ans = ans + (s if G[-1][l] == '+' else m)
    print(ans)

one()
two()
