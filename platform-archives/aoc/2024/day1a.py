a = []
b = []
for line in open("in.txt"):
    line = line.strip().split("   ")
    a.append(int(line[0]))
    b.append(int(line[-1]))
a.sort()
b.sort()

#ans = sum(abs(a[i] - b[i]) for i in range(len(a)))
ans = 0
for i in range(len(a)):
    ans += abs(a[i] - b[i])

print("sum:", ans)

