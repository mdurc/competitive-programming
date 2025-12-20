s = [list(map(int,l.strip())) for l in open(0)]

rows = len(s)
cols = len(s[0])

def search(curr, i, j, ends):
    if curr == 9:
        ends.add((i,j))
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
        ends = set()
        search(0, i, j, ends)
        ans += len(ends)
print(ans)
