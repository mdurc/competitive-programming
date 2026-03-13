import re

file = open(0).read().strip().split("\n")

ans = 0
for l in file:
    n = list(re.findall(r"\d", l))
    if len(n) <= 0: continue
    a, b = n[0], n[-1]
    ans += int(a+b)

print("part a:", ans)


words = {"one":1,
         "two":2,
         "three":3,
         "four":4,
         "five":5,
         "six":6, 
         "seven":7,
         "eight":8,
         "nine":9}

def convert(i):
    if (i.isdigit()): return i
    return str(words[i])

ans = 0
for l in file:
    n = list(re.findall(r"\d|one|two|three|four|five|six|seven|eight|nine", l))
    a, b = n[0], n[-1]
    ans += int(convert(a) + convert(b))

print("part b:", ans)
