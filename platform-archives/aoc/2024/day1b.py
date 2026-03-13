a = []
b = []
for line in open("in.txt"):
    line = line.strip().split("   ")
    a.append(int(line[0]))
    b.append(int(line[-1]))
a.sort()
b.sort()

#ans = sum(a[i]*b.count(a[i]) for i in range(len(a)))
ans = 0
for i in range(len(a)):
    ans += a[i] * b.count(a[i])

print("sum:", ans)

