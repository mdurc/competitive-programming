from collections import deque
from functools import cache
import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().splitlines()
chg = [g.split()[0].strip("[]") for g in G]
volts = [nums(g.split()[-1]) for g in G]
btns = [[nums(b) for b in g.split()[1:-1]] for g in G]

def one():
    visit = set()
    @cache
    def solve(idx, s):
        if s in visit: return -1
        visit.add(s)
        if s == chg[idx]:
            return 0
        res = float('inf')
        for b in btns[idx]:
            n = ""
            for i in range(len(s)):
                if i in b:
                    if s[i] == '#': n += '.'
                    else: n += '#'
                else:
                    n += s[i]
            x = solve(idx, n)
            if x != -1:
                res = min(res, 1 + x)
        return res

    res = 0
    for i in range(len(G)):
        visit = set()
        res += solve(i, "."*len(chg[i]))
    print(res)

def two():
    res = 0
    for i in range(len(G)):
        res += 0
    print(res)

one()
two()
