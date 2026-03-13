

import re

text = open("in.txt").read()
x = re.findall(r"mul\([0-9]+,[0-9]+\)|do\(\)|don't\(\)", text)
ans = 0
do = True
for y in x:
    if y == "do()":
        do = True
    elif y ==  "don't()":
        do = False
    elif do:
        z = re.match(r"mul\((\d+),(\d+)\)", y)
        if z:
            ans += int(z.group(1)) * int(z.group(2))
print("ans:", ans)


"""
# first attempt

import re

ans = 0
do = True
for line in open("in.txt"):
    line = line.strip();
    for i in range(len(line)):
        if line[i:i+7] == "don't()":
            do = False
        elif line[i:i+4] == "do()":
            do = True
        elif do:
            x = re.search(r"^mul\(([0-9]+),([0-9]+)\)", line[i:])
            if x:
                ans += int(x.group(1)) * int(x.group(2))


print("ans:", ans)
"""
