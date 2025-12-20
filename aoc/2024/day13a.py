
# no regex
#s = open(0).read().strip().split("\n\n")
#s = [l.strip().split("\n") for l in s]
#
#buttons = []
#for i in range(len(s)):
#    buttons.append([])
#    for j in range(2):
#        delta = s[i][j].split(", ")
#        dx = int(delta[0].split("+")[1])
#        dy = int(delta[1].split("+")[1])
#        buttons[i].append((dx, dy))
#
#    delta = s[i][2].split(", ")
#    dx = int(delta[0].split("=")[1])
#    dy = int(delta[1].split("=")[1])
#    buttons[i].append((dx, dy))


import re
ans = 0

# brute force
#for block in open(0).read().strip().split("\n\n"):
#    ax, ay, bx, by, px, py = map(int,re.findall(r"\d+", block))
#    min_score = -1
#    for i in range(101):
#        for j in range(101):
#            if ax*i + bx*j == px and ay*i + by*j == py:
#                if min_score == -1: min_score = i*3 + j
#                else: min_score = min(min_score, i*3 + j)
#    if min_score != -1:
#        ans += min_score

# math
for block in open(0).read().strip().split("\n\n"):
    ax, ay, bx, by, px, py = map(int,re.findall(r"\d+", block))
    # solve for ax*i + bx*j == px and ay*i + by*j == py:
    # system of 2 equations (subtract):
    # axby*i + bxby*j = pxby
    # aybx*i + bybx*j = pybx
    i = (px*by-py*bx)/(ax*by-ay*bx)
    j = (px-ax*i)/bx
    if i%1==0 and j%1==0:
        if i <= 100 and j <= 100:
            ans += int(3*i + j)

print(ans)
