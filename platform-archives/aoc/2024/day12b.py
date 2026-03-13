
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

def sides(region):
 edges = {}
 for r, c in region:
     for nr, nc in [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]:
         if (nr, nc) in region: continue
         er = (r + nr) / 2
         ec = (c + nc) / 2
         edges[(er, ec)] = (er - r, ec - c)
 seen = set()
 side_count = 0
 for edge, direction in edges.items():
     if edge in seen: continue
     seen.add(edge)
     side_count += 1
     er, ec = edge
     if er % 1 == 0: # column edge
         for dr in [-1, 1]:
             cr = er + dr
             while edges.get((cr, ec)) == direction:
                 seen.add((cr, ec))
                 cr += dr
     else: # row edge
         for dc in [-1, 1]:
             cc = ec + dc
             while edges.get((er, cc)) == direction:
                 seen.add((er, cc))
                 cc += dc
 return side_count

print(sum(len(region) * sides(region) for region in regions))
