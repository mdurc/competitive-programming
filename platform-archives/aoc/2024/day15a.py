grid, movement = open(0).read().strip().split("\n\n")
grid = [list(l) for l in grid.split("\n")]
movement = list(movement.replace("\n",""))

rows = len(grid)
cols = len(grid[0])

pr, pc = 0, 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "@":
            pr, pc = i, j

grid[pr][pc] = "."

for m in movement:
    dr, dc = {"^": (-1, 0),
              ">": (0, 1),
              "v": (1, 0),
              "<": (0,-1)}[m]
    nr, nc = pr+dr, pc+dc
    if grid[nr][nc] == "#": continue
    if grid[nr][nc] == "O":
        while grid[nr][nc] == "O":
            nr += dr
            nc += dc
        if grid[nr][nc] == ".":
            grid[nr][nc] = "O"
            pr += dr
            pc += dc
            grid[pr][pc] = "."
    else:
        pr += dr
        pc += dc

#grid[pr][pc] = "@"
#for l in grid:
#    print(*l, sep='')

ans = 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "O":
            ans += 100*i + j
print(ans)


