
import itertools

s = open(0).read().strip().split("\n")

ans = 0

for l in s:
    x, y = l.split(":")
    x = int(x)
    y = y.split()
    y = list(map(int, y))
    ops = ["*", "+"]

    perms = list(itertools.product(ops,repeat=len(y)-1))

    for i in range(len(perms)):
        curr = y[0]
        for j in range(len(perms[i])):
            if perms[i][j] == "*":
                curr *= y[j+1]
            else:
                curr += y[j+1]
        if curr == x:
            ans+=x
            break

print("ans:", ans)
