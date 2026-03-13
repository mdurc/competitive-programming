import re

a, b = open("in.txt").read().split("\n\n")

a = a.strip().split("\n")
b = b.strip().split("\n")

ans = 0

m = {}

for x in a:
    # 43|55
    r = re.match(r"(\d+)\|(\d+)", x)
    if r:
        key = int(r.group(1))
        val = int(r.group(2))
        if key in m:
            m[key].append(val)
        else:
            m[key] = [val]

def valid(level):
    for i in range(1, len(level)):
        for j in range(i):
            if level[i] in m.keys():
                if level[j] in m[level[i]]:
                        return False
    return level[len(level)//2]


for level in b:
    level = list(map(int, level.split(",")))
    v = valid(level)
    if v:
        ans += v


print("ans:", ans)

