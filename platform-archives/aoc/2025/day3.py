import re
import sys
sys.setrecursionlimit(10**6)
def nums(s): return [int(x) for x in re.findall(r"-?\d+", s)]

G = open(0).read().strip()

def one():
    ans = 0
    for line in G.split():
        nums = list(map(int, list(line)))
        l, r = 0, 1
        mx = 0
        while r < len(nums):
            mx = max(mx, nums[l] * 10 + nums[r])
            if nums[r] > nums[l]:
                l = r
            r += 1
        ans += mx
    print(ans)

def two():
    ans = 0
    for line in G.split():
        nums = list(map(int, list(line)))
        n = len(nums)
        dp = [[0] * 13 for _ in range(n+1)]
        # dp[i][j]: max sum from considering items [1..i], with j values used
        for i in range(1, n+1):
            dp[i][1] = nums[i-1]
        for i in range(1, n+1):
            for j in range(1, 13):
                dp[i][j] = max(dp[i-1][j-1] * 10 + nums[i-1], dp[i-1][j])
        ans += dp[n][12]
    print(ans)

one()
two()
