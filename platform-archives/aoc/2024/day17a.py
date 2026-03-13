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

regs, prog = open(0).read().strip().split("\n\n")

A, B, C = nums(regs)
prog = nums(prog)


def combo(c):
    if 0 <= c <= 3:
        return c
    elif c == 4:
        return A
    elif c == 5:
        return B
    elif c == 6:
        return C
    return -1

pc = 0
output = []
while pc < len(prog):
    ins = prog[pc]
    op = prog[pc+1]
    pc += 2

    if ins == 0:
        A = A >> combo(op)
    elif ins == 1:
        B ^= op
    elif ins == 2:
        B = combo(op)%8
    elif ins == 3:
        if A != 0:
            pc = op
    elif ins == 4:
        B ^= C
    elif ins == 5:
        output.append(combo(op)%8)
    elif ins == 6:
        B = A >> combo(op)
    elif ins == 7:
        C = A >> combo(op)

print(",".join(map(str, output)))
