
s = [list(line.strip()) for line in open(0)]

rows = len(s)
cols = len(s[0])


a = {}
for i in range(rows):
    for j in range(cols):
        if s[i][j] != ".":
            if s[i][j] in a: a[s[i][j]].append((i,j))
            else: a[s[i][j]] = [(i,j)]

ans = set()
for freq in a.values():
    for i in range(len(freq)):
        for j in range(i+1, len(freq)):
            r1, c1 = freq[i]
            r2, c2 = freq[j]
            ans.add((2*r1-r2, 2*c1-c2))
            ans.add((2*r2-r1, 2*c2-c1))

print(len([0 for r,c in ans if 0<=r<rows and 0<=c<cols]))
