from collections import deque, defaultdict, Counter
from itertools import product
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

def solve(s, grid):
    pos = {}
    for r in range(len(grid)):
        for c in range(len(grid[r])):
            if grid[r][c] is not None: pos[grid[r][c]] = (r,c)
    seqs = {}
    for x in pos:
        for y in pos:
            if x == y:
                # fastest way to get from x to y
                seqs[(x,y)] = ["A"]
                continue
            posibilities = []
            pq = deque([(pos[x], "")])
            optimal = float("inf")
            while pq:
                (r,c), moves = pq.popleft()
                br = False
                for nr, nc, nm in [(r-1,c,"^"),(r+1,c,"v"),(r,c-1,"<"),(r,c+1,">")]:
                    if not(0<=nr<len(grid) and 0<=nc<len(grid[r])): continue
                    if grid[nr][nc] is None: continue
                    if grid[nr][nc] == y:
                        if optimal < len(moves) + 1:
                            br = True
                            break
                        optimal = len(moves) + 1
                        posibilities.append(moves+nm+"A")
                    else:
                        pq.append(((nr, nc), moves+nm))
                if br: break
            seqs[(x,y)] = posibilities
    options = [seqs[(x,y)] for x,y in zip("A" + s, s)]
    return ["".join(x) for x in product(*options)]


num_keypad = [
        ["7", "8", "9"],
        ["4", "5", "6"],
        ["1", "2", "3"],
        [None, "0", "A"],
]
dir_keypad = [
        [None, "^", "A"],
        ["<", "v", ">"],
]

G = open(0).read().strip().split("\n")
total = 0
for l in G:
    print(l)
    r1 = solve(l, num_keypad)
    front = r1
    for _ in range(2):
        possible_next = []
        for seq in front:
            possible_next += solve(seq, dir_keypad)
        min_len = min(map(len, possible_next))
        front = [seq for seq in possible_next if len(seq) == min_len]
    total += len(front[0]) * int(l[:-1])
print(total)

