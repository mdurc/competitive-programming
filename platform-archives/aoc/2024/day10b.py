s = [list(map(int,l.strip())) for l in open(0)]

rows = len(s)
cols = len(s[0])

def search(curr, i, j, ends):
    if curr == 9:
        if (i,j) not in ends: ends[(i,j)]=0
        ends[(i,j)] += 1
        return
    curr = s[i][j]
    dirs = [(1,0), (0,1), (-1,0), (0,-1)]
    for dr,dc in dirs:
        if not(0<=i+dr<rows and 0<=j+dc<cols): continue
        if s[i+dr][j+dc] != curr+1: continue
        search(curr+1, i+dr, j+dc, ends)

ans = 0
for i in range(rows):
    for j in range(cols):
        if s[i][j] != 0: continue
        ends = dict()
        search(0, i, j, ends)
        ans += sum(l for l in ends.values())
print(ans)
