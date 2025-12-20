import heapq
from collections import deque

grid = open(0).read().strip().split("\n")
grid = [list(l) for l in grid]

rows = len(grid)
cols = len(grid[0])


pr, pc = 0, 0
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == "S":
            pr, pc = i, j


p = [(0, pr, pc, 0, 1)]
lowest_cost = {(pr, pc, 0, 1): 0}
backtrack = {}
end_states = set()

best = float("inf")
while p:
    cost, r, c, dr, dc = heapq.heappop(p)
    if cost > lowest_cost.get((r, c, dr, dc), float("inf")): continue

    if grid[r][c] == "E":
        if cost > best: break
        best = cost
        end_states.add((r,c,dr,dc))

    opts = [(cost+1, r+dr, c+dc, dr, dc),
            (cost+1000, r, c, -dc, dr),
            (cost+1000, r, c, dc, -dr)]
    for o in opts:
        if grid[o[1]][o[2]] == "#": continue
        new_cost = o[0]
        new_pos = (o[1], o[2], o[3], o[4])
        lowest = lowest_cost.get(new_pos, float("inf"))
        if new_cost > lowest: continue
        if new_cost < lowest:
            backtrack[new_pos] = set()
            lowest_cost[new_pos] = new_cost
        backtrack[new_pos].add((r, c, dr, dc))

        heapq.heappush(p, o)

# backtracking from the ends
states = deque(end_states)
seen = set(end_states)

while states:
    key = states.popleft()
    for last in backtrack.get(key, []):
        if last in seen: continue
        seen.add(last)
        states.append(last)

print(len(set((r,c) for r, c, _, _ in seen)))
