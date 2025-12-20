from collections import deque, defaultdict, Counter
import heapq
import re
import sys
sys.setrecursionlimit(10**6)
DIRS = [(-1,0),(0,1),(1,0),(0,-1)] # up right down left
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

#grid = open(0).read().strip().split("\n")
#grid = [list(l) for l in grid]
#rows = len(grid)
#cols = len(grid[0])

G = open(0).read().strip().split("\n\n")
bits, opts = [l.split("\n") for l in G]

known = {}
for b in bits:
    x, y = b.split(": ")
    known[x] = int(y)

formulas = {}
for o in opts:
    x, op, y, z = o.replace(" -> ", " ").split()
    formulas[z] = (op, x, y)


def pp(wire, depth=0):
    if wire[0] in "xy": return " "*depth + wire
    op, x, y = formulas[wire]
    return " "*depth + op + " (" + wire + ")\n" + pp(x, depth+1) + "\n" + pp(y, depth+1)

#print(pp("z01"))

def make_wire(char, num):
    return char + str(num).rjust(2, "0")

def verify_intermediate_xor(wire, num):
    print("vx", wire, num)
    op, x, y = formulas[wire]
    if op != "XOR": return False
    return sorted([x,y]) == [make_wire("x", num), make_wire("y", num)]

def verify_carry_bit(wire, num):
    print("vc", wire, num)
    op, x, y = formulas[wire]
    if num == 1:
        if op != "AND": return False
        return sorted([x,y]) == ["x00", "y00"]
    if op != "OR": return False
    return verify_direct_carry(x, num - 1) and verify_recarry(y, num-1) or verify_direct_carry(y, num-1) and verify_recarry(x, num-1)

def verify_direct_carry(wire, num):
    print("vd", wire, num)
    op, x, y = formulas[wire]
    if op!="AND": return False
    return sorted([x,y]) == [make_wire("x", num), make_wire("y", num)]

def verify_recarry(wire, num):
    print("vr", wire, num)
    op, x, y = formulas[wire]
    if op != "AND": return False
    return verify_intermediate_xor(x, num) and verify_carry_bit(y, num) or verify_intermediate_xor(y, num) and verify_carry_bit(x, num)

def verify_z(wire, num):
    print("vz", wire, num)
    op, x, y = formulas[wire]
    if op != "XOR": return False
    if num == 0: return sorted([x,y]) == ["x00", "y00"]
    return verify_intermediate_xor(x, num) and verify_carry_bit(y, num) or verify_intermediate_xor(y, num) and verify_carry_bit(x, num)


def verify(num):
    return verify_z(make_wire("z", num), num)

i = 0
while True:
    if not verify(i): break
    i += 1

print("Failed on", make_wire("z", i))


# gdd and z05
# cwt and z09
# jmv and css
# pqt and z37

print(",".join(sorted(["gdd", "z05", "cwt", "z09", "jmv", "css", "pqt", "z37"])))
