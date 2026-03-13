import heapq

grid = open(0).read().strip().split("\n")
grid = [list(l) for l in grid]

rows = len(grid)
cols = len(grid[0])


pr, pc = 0, 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "S":
            pr, pc = i, j


p = [(0, pr, pc, 0, 1)]
visited = {(pr, pc, 0, 1)}

while p:
    cost, r, c, dr, dc = heapq.heappop(p)
    visited.add((r, c, dr, dc))
    if grid[r][c] == "E":
        print(cost)
        break
    opts = [(cost+1, r+dr, c+dc, dr, dc),
            (cost+1000, r, c, -dc, dr),
            (cost+1000, r, c, dc, -dr)]
    for o in opts:
        if grid[o[1]][o[2]] == "#": continue
        pos = (o[1], o[2], o[3], o[4])
        if pos in visited: continue
        visited.add(pos)
        heapq.heappush(p, o)
