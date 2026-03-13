import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().strip()

def one():
    ans = 0
    for i in G.split(","):
        a, b = map(int, i.split("-"))
        for i in range(a, b+1):
            x = str(i)
            if len(x) % 2 == 0 and x == x[:len(x)//2] * 2:
                ans += i
    print(ans)

def two():
    ans = 0
    for i in G.split(","):
        a, b = map(int, i.split("-"))
        for i in range(a, b+1):
            x = str(i)
            for j in range(1, (len(x)//2) + 1):
                if len(x) % j == 0 and x == x[:j] * (len(x) // j):
                    ans += i
                    break
    print(ans)

one()
two()
