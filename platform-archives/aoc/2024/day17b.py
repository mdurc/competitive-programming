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

"""
Register A: 25986278
Register B: 0
Register C: 0

Program: 2,4,1,4,7,5,4,1,1,4,5,5,0,3,3,0

2,4: B = A % 8
1,4: B = B ^ 4
7,5: C = A >> B
4,1: B = B ^ C
1,4: B = B ^ 4
5,5: out(B%8)
0,3: A = A >> 3
3,0: jnz A: pc = 0


working backwards:
outputting 0: A must be <= 7, so that A>>3 ends in 0 and halts
- Say A ends as 0 (from start):
    B = 0, 4
    C = 0
    B = 4
    out: B % 8 : 4, wrong cause we want 0 of output
- Say A ends as 1:
    B = 1, b0101 --> 5
    C = 0
    B = 5, 0101 ^ 0100 --> 0001 = 1
    out B%8 --> 1, wrong
...
- Say A ends as 4: **
    B = 4, 0
    C = 4
    B = 4, 0
    out B%8 --> 0 correct
    A = 0 correct

So in the previous loop before jnz, A has to become 4: A >> 3 == 4
- So A << 3 is what the old A value was: 4*8 = 32
- So A must have been between 32 and 40. Where 39 is: 0b100111
    - This is 7 options, so we can solve for the next value of A
- Say A was 35:
    B = 3, 7
    C = 0
    B = 7, 3
    out B%8 --> 3 correct
    A = 4, correct



A ends as: ..... 35, 4
"""

# ans will be the value that will be outputted, starting from the end
# ans starts at 0 because it is the last one
def find(program, ans, depth):
    if len(program) == 0: return ans

    for t in range(8):
        a = (ans << 3) + t
        # a cannot be zero until the very end
        if depth == 0 and a == 0: continue
        b = a % 8
        b = b ^ 4
        c = a >> b
        b = b ^ c
        b = b ^ 4
        if b % 8 == program[-1]:
            sub = find(program[:-1], a, depth+1)
            if sub is None: continue
            # print(sub) # for all solutions
            return sub

print(find(prog, 0, 0))
