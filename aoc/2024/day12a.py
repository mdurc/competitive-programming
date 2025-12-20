
s = [list(l.strip()) for l in open(0)]

rows = len(s)
cols = len(s[0])

regions = []
seen = set()

for r in range(rows):
    for c in range(cols):
        if (r, c) in seen: continue
        seen.add((r, c))
        region = {(r, c)}
        q = [(r,c)]
        letter = s[r][c]

        # breadth first search
        while q:
            cr, cc = q.pop(0)
            for nr, nc in [(cr - 1, cc), (cr + 1, cc), (cr, cc - 1), (cr, cc + 1)]:
                if not(0<=nr<rows and 0<=nc<cols): continue
                if s[nr][nc] != letter: continue
                if (nr, nc) in region: continue
                region.add((nr, nc))
                q.append((nr, nc))
        seen |= region
        regions.append(region)

def perimeter(region):
    perm = len(region) * 4
    for r, c in region:
        for nr, nc in [(r-1,c), (r+1,c), (r,c-1), (r,c+1)]:
            if (nr,nc) in region:
                perm -=  1
    return perm

print(sum([len(region) * perimeter(region) for region in regions]))

# Recursively:
#visited = []
#plots = {}
#def grow(i, j, index, letter):
#    if not(0<=i<rows and 0<=j<cols) or s[i][j] != letter:
#        plots[index][1] += 1
#        return
#    if (i,j) in visited: return
#    visited.append((i,j))
#    if index not in plots:
#        plots[index] = [1,0]
#    else:
#        a = plots[index]
#        a[0] += 1
#    for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
#        #if not(0<=i+dr<rows and 0<=j+dc<cols): continue
#        grow(i+dr, j+dc, index, letter)
#
#count = -1
#for i in range(rows):
#    for j in range(cols):
#        if (i,j) not in visited:
#            count+=1
#        grow(i,j, count, s[i][j])
#
#ans = 0
#for a in plots.values():
#    ans += a[0]*a[1]
#print(ans)



