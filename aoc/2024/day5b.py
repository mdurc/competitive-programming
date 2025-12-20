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


invalid = []
for level in b:
    level = list(map(int, level.split(",")))
    v = valid(level)
    if not v:
        invalid.append(level)

count = 1
for i in range(len(invalid)):
    print(count,"/",len(invalid),sep="")
    level = invalid[i]

    new_level = [level[0]]
    index = 1
    for j in range(1, len(level)):
        for k in range(len(new_level)):
            if level[j] in m.keys() and new_level[k] in m[level[j]]:
                index = k
                break
            elif new_level[k] in m.keys() and level[j] in m[new_level[k]]:
                index = k+1
        new_level.insert(index, level[j])

    ans += new_level[len(new_level)//2]
    count += 1

print("ans:", ans)





