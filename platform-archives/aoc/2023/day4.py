from collections import defaultdict

s = [l.strip().split()[2:] for l in open(0)]
s = [" ".join(l).split(" | ") for l in s]
s = [[l[0].split(),l[1].split()] for l in s]


ans = 0
for i in s:
    #a = len(set(i[0]).intersection(set(i[1])))
    a = len(set(i[0]) & set(i[1]))
    if a > 0:
        #ans += 2 ** (a-1)
        ans += 1 << (a-1)
print("part a:", ans)


copies = defaultdict(int)

for i in range(len(s)):
    copies[i] = 1

for x,y in copies.items():
    i = s[x]
    for z in range(y):
        a = len(set(i[0]) & set(i[1]))
        if a > 0:
            for n in range(x+1, x+a+1):
                copies[n] += 1

print("part b:", sum(copies.values()))
