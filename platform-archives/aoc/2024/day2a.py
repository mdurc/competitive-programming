ans = 0
for line in open("in.txt"):
    t = list(map(int, line.strip().split()))
    if len(t) == 1:
        ans = 1
        continue
    inc = t[1] > t[0]
    flag = True
    for i in range(1, len(t)):
        if inc and ((t[i] - t[i-1]) > 3 or (t[i]-t[i-1] < 1)):
            flag = False
            break
        elif not inc and ((t[i-1] - t[i]) > 3 or (t[i-1]-t[i] < 1)):
            flag = False
            break
    if flag:
        ans += 1
print("ans:", ans)

