import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]
# open(0).read()
