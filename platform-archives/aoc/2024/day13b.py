import re
ans = 0

for block in open(0).read().strip().split("\n\n"):
    ax, ay, bx, by, px, py = map(int,re.findall(r"\d+", block))
    # solve for ax*i + bx*j == px and ay*i + by*j == py:
    # system of 2 equations (subtract):
    # axby*i + bxby*j = pxby
    # aybx*i + bybx*j = pybx
    px += 10000000000000
    py += 10000000000000
    i = (px*by-py*bx)/(ax*by-ay*bx)
    j = (px-ax*i)/bx
    if i%1==0 and j%1==0:
        ans += int(3*i + j)

print(ans)
