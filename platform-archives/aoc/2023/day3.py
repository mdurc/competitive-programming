

s = [list(s.strip()) for s in open(0).read().strip().split("\n")]

dig = [str(i) for i in range(10)]
curr_dig = ""
ans = 0
flag = False

for i in range(len(s)):
    for j in range(len(s[i])):
        if s[i][j] not in dig:
            if flag and curr_dig:
                ans += int(curr_dig)
            flag = False
            curr_dig = ""
            continue
        else:
            curr_dig += s[i][j]
        if not flag:
            for dr in [-1, 0, 1]:
                for dc in [-1, 0, 1]:
                    if dr == dc == 0: continue
                    if not(0<=i+dr<len(s) and 0<=j+dc<len(s[i])): continue
                    c = s[i+dr][j+dc]
                    if c!="." and c not in dig:
                        flag = True
    # handle valid digit at EOL
    if curr_dig and flag:
        ans+=int(curr_dig)
        curr_dig = ""
        flag = False

print("part a:", ans)

curr_dig = ""
ans = 0
gear_ind = tuple()

gears = {}

for i in range(len(s)):
    for j in range(len(s[i])):
        if s[i][j] not in dig:
            if gear_ind and curr_dig:
                if gear_ind in gears.keys():
                    gears[gear_ind].append(int(curr_dig))
                else:
                    gears[gear_ind] = [int(curr_dig)]
            gear_ind = tuple()
            curr_dig = ""
            continue
        else:
            curr_dig += s[i][j]
        if not gear_ind:
            for dr in [-1, 0, 1]:
                for dc in [-1, 0, 1]:
                    if dr == dc == 0: continue
                    if not(0<=i+dr<len(s) and 0<=j+dc<len(s[i])): continue
                    c = s[i+dr][j+dc]
                    if c == "*":
                        gear_ind = (i+dr, j+dc)
    # handle valid digit at EOL
    if curr_dig and gear_ind:
        if gear_ind in gears.keys():
            gears[gear_ind].append(int(curr_dig))
        else:
            gears[gear_ind] = [int(curr_dig)]

        curr_dig = ""
        gear_ind = tuple()

for g in gears.keys():
    if len(gears[g]) != 2: continue
    ans += gears[g][0] * gears[g][1]

print("part b:", ans)
