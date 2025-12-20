from collections import deque
import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = [nums(l) for l in open(0).read().strip().split("\n")]

def one():
    areas = []
    for i, (a,b) in enumerate(G):
        for j, (c,d) in enumerate(G):
            if i < j:
                areas.append((abs(c-a)+1) * (abs(d-b)+1))
    print(max(areas))

def two():
    xs = sorted({x for x,_ in G})
    ys = sorted({y for _,y in G})

    grid = [[0]*(len(ys)*2-1) for _ in range(len(xs)*2-1)]
    for (x1,y1), (x2,y2) in zip(G,G[1:]+G[:1]):
        cx1, cx2 = sorted([xs.index(x1)*2, xs.index(x2)*2])
        cy1, cy2 = sorted([ys.index(y1)*2, ys.index(y2)*2])
        for cx in range(cx1, cx2+1):
            for cy in range(cy1, cy2+1):
                grid[cx][cy] = 1

    outside = {(-1,-1)}
    q = deque(outside)
    while q:
        tx, ty = q.popleft()
        for nx, ny in [(tx-1,ty),(tx+1,ty),(tx,ty-1),(tx,ty+1)]:
            if nx < -1 or ny < -1 or nx > len(grid) or ny > len(grid[0]): continue
            if 0 <= nx < len(grid) and 0 <= ny < len(grid[0]) and grid[nx][ny] == 1: continue
            if (nx,ny) in outside: continue
            outside.add((nx,ny))
            q.append((nx,ny))
    for x in range(len(grid)):
        for y in range(len(grid[0])):
            if (x,y) not in outside:
                grid[x][y] = 1

    ps = [[0]*len(i) for i in grid]
    for x in range(len(ps)):
        for y in range(len(ps[0])):
            left = ps[x-1][y] if x > 0 else 0
            top = ps[x][y-1] if y > 0 else 0
            topleft = ps[x-1][y-1] if x > 0 < y else 0
            ps[x][y] = left + top - topleft + grid[x][y]

    def valid(x1, y1, x2, y2):
        cx1, cx2 = sorted([xs.index(x1)*2, xs.index(x2)*2])
        cy1, cy2 = sorted([ys.index(y1)*2, ys.index(y2)*2])
        left = ps[cx1-1][cy2] if cx1 > 0 else 0
        top = ps[cx2][cy1-1] if cy1 > 0 else 0
        topleft = ps[cx1-1][cy1-1] if cx1 > 0 < cy1 else 0
        cnt = ps[cx2][cy2] - left - top + topleft
        return cnt == (cx2-cx1+1) * (cy2-cy1+1)

    print(max([(abs(x1-x2)+1) * (abs(y1-y2)+1) for i, (x1,y1) in enumerate(G) for x2,y2 in G[:i] if valid(x1,y1,x2,y2)]))



one()
two()
