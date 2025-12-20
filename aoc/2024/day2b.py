ans = 0
for line in open("in.txt"):
    t = list(map(int, line.strip().split()))
    if len(t) == 1:
        ans += 1
        continue
    for x in range(len(t)):
        new_t = t[:x] + t[x+1:]
        inc = new_t[1] > new_t[0]
        flag = True
        for i in range(1, len(new_t)):
            if inc and not (1 <= (new_t[i] - new_t[i-1]) <= 3):
                flag = False
                break
            elif not inc and not (1 <= (new_t[i-1] - new_t[i]) <= 3):
                flag = False
                break
        if flag:
            ans += 1
            break
print("ans:", ans)

