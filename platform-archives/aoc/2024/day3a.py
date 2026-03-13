

import re

text = open("in.txt").read()
x = re.findall(r"mul\(([0-9]+),([0-9]+)\)", text)
ans = 0
for y in x:
    ans += int(y[0]) * int(y[1])
print("ans:", ans)



"""
# first attempt:
import re

ans = 0
for line in open("in.txt"):
    line = line.strip();
    for i in range(len(line)-7):
        x = re.search(r"^mul\(([0-9]+),([0-9]+)\)", line[i:])
        if x:
            ans += int(x.group(1)) * int(x.group(2))


print("ans:", ans)
"""
