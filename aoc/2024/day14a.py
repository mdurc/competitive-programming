import re

robots = []
for l in open(0):
    robots.append(tuple(map(int, re.findall(r"-?\d+", l.strip()))))

HEIGHT = 103
WIDTH = 101

positions = []
iteration = 6888 # for christmas tree
#iteration = 100
for px, py, vx, vy in robots:
    positions.append(((px + vx*iteration)%WIDTH, (py + vy*iteration)%HEIGHT))

quad = [0] * 4

column_mid = WIDTH//2
vertical_mid = HEIGHT//2

for px, py in positions:
    if px == column_mid or py == vertical_mid: continue
    if px < column_mid:
        if py < vertical_mid:
            quad[0] += 1
        else:
            quad[1] += 1
    elif py < vertical_mid:
        quad[2] += 1
    else:
        quad[3] += 1

ans = 1
for q in quad:
    ans *= q
print(ans)

# to print
# grid = [[0]*WIDTH for _ in range(HEIGHT)]
# for px, py in positions:
#     grid[py][px] += 1
# for i in grid:
#     print(*i, sep="")

# print tree
grid = [[' ']*WIDTH for _ in range(HEIGHT)]
for px, py in positions:
    grid[py][px] = '#'
for i in grid:
    print(*i, sep="")
