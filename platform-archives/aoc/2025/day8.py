from collections import defaultdict
import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = [nums(l) for l in open(0).read().strip().split("\n")]

def reset():
    global parent, size
    parent = {i:i for i in range(len(G))}
    size = defaultdict(lambda:1)
def find(a):
    if parent[a] == a:
        return a
    parent[a] = find(parent[a])
    return parent[a]
def merge(a, b):
    pa, pb = find(a), find(b)
    if pa == pb: return
    size[pb] += size[pa]
    size[pa] = 0
    parent[pa] = pb

d = []
for i, (a,b,c) in enumerate(G):
    for j, (x,y,z) in enumerate(G):
        if i < j:
            d.append(((a-x)**2 + (b-y)**2 + (c-z)**2, i, j))
d = sorted(d)

def one():
    reset()
    for (_,i,j) in d[:1000]:
        merge(i,j)
    s = sorted(size.values())
    print(s[-1] * s[-2] * s[-3])

def two():
    reset()
    for (_,i,j) in d:
        merge(i,j)
        if size[find(j)] == len(G):
            print(G[i][0] * G[j][0])
            break

one()
two()
