import re

robots = []
for l in open(0):
    robots.append(tuple(map(int, re.findall(r"-?\d+", l.strip()))))

HEIGHT = 103
WIDTH = 101

ans = float("inf")
it = 0
for second in range(WIDTH * HEIGHT):

    positions = []
    for px, py, vx, vy in robots:
        positions.append(((px + vx*second)%WIDTH, (py + vy*second)%HEIGHT))

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

    curr = 1
    for q in quad:
        curr *= q
    if curr < ans:
        ans = curr
        it = second

print(it)
