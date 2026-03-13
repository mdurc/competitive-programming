
s = [list(l) for l in open("in.txt").read().strip().split("\n")]
r = len(s)
c = len(s[0])


cx, cy = 0, 0
for i in range(r):
    for j in range(c):
        if s[i][j] in "<>^V":
            cx, cy = i, j


dirs = [(-1,0), (0,1), (1,0), (0,-1)]

ans = 0

scx, scy = cx, cy
for i in range(r):
    for j in range(c):
        if i == scx and j == scy: continue
        if s[i][j] == "#": continue

        s[i][j] = "#"
        cd = 0
        cx, cy = scx, scy
        visited = set()
        while cx in range(r) and cy in range(c) and (cx, cy, cd) not in visited:
            visited.add((cx, cy, cd))
            while True:
                move_dir = dirs[cd]
                nx, ny = cx+move_dir[0], cy+move_dir[1]
                if nx in range(r) and ny in range(c) and s[nx][ny] == "#":
                    cd = (cd + 1) % 4
                else:
                    cx, cy = nx, ny
                    break
        if (cx, cy, cd) in visited:
            ans += 1
        s[i][j] = "."

print("ans:", ans)

