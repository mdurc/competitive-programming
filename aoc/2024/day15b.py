from collections import deque

grid, movement = open(0).read().strip().split("\n\n")
grid = [list(l) for l in grid.split("\n")]
movement = list(movement.replace("\n",""))

rows = len(grid)
cols = len(grid[0])

big = []
for i in range(rows):
    big.append([])
    for j in range(cols):
        if grid[i][j] == "@":
            big[-1].append("@")
            big[-1].append(".")
        elif grid[i][j] == "O":
            big[-1].append("[")
            big[-1].append("]")
        else:
            c = grid[i][j]
            big[-1].append(c)
            big[-1].append(c)


rows = len(big)
cols = len(big[0])
pr, pc = 0, 0
for i in range(rows):
    for j in range(cols):
        if big[i][j] == "@":
            pr, pc = i, j

grid = big
grid[pr][pc] = "."

for m in movement:
    dr, dc = {"^": (-1, 0),
              ">": (0, 1),
              "v": (1, 0),
              "<": (0,-1)}[m]
    nr, nc = pr+dr, pc+dc
    if grid[nr][nc] == "#": continue
    if grid[nr][nc] == ".":
        pr, pc = nr, nc
        continue

    visited = set()
    que = deque([(pr, pc)])

    dontmove = False
    while len(que) > 0:
        cr, cc = que.popleft()
        cr += dr
        cc += dc

        if (cr, cc) in visited: continue

        c = grid[cr][cc]
        if c == "#":
            dontmove = True
            break

        if c == "[":
            que.append((cr, cc))
            que.append((cr, cc+1))
            visited.add((cr, cc))
            visited.add((cr, cc+1))
        elif c == "]":
            que.append((cr, cc))
            que.append((cr, cc-1))
            visited.add((cr, cc))
            visited.add((cr, cc-1))
    if dontmove: continue
    #print(visited)
    # move all boxes
    copy = [list(row) for row in grid]
    for br, bc in visited:
        grid[br][bc] = "."
    for br, bc in visited:
        grid[br + dr][bc + dc] = copy[br][bc]
    pr += dr
    pc += dc


#grid[pr][pc] = "@"
#for l in grid:
#    print(*l, sep='')

ans = 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "[":
            ans += 100*i + j
print(ans)


