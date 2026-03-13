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

G = open(0).read().strip().split("\n\n")
bits, opts = [l.split("\n") for l in G]

known = {}
for b in bits:
    x, y = b.split(": ")
    known[x] = int(y)

formulas = {}
for o in opts:
    x, op, y, z = o.replace(" -> ", " ").split()
    formulas[z] = (op, x, y)

operators = {
        "OR": lambda x,y: x|y,
        "AND": lambda x,y: x&y,
        "XOR": lambda x,y: x^y
}

def calc(wire):
    if wire in known: return known[wire]
    op, x, y = formulas[wire]
    known[wire] = operators[op](calc(x), calc(y))
    return known[wire]

z = []
i = 0
while True:
    key = "z" + str(i).rjust(2,"0")
    if key not in formulas: break
    z.append(calc(key))
    i+=1

print(int("".join(map(str,z[::-1])), 2))

