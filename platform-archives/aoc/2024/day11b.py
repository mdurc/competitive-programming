
from functools import cache

s = list(map(int, open(0).read().strip().split()))

@cache
def blink(stone_value, num_blinks):
    if num_blinks == 0: return 1

    if stone_value == 0:
        return blink(1, num_blinks-1)
    else:
        a = str(stone_value)
        if len(a)%2 == 0:
            return blink(int(a[:len(a)//2]), num_blinks-1) +\
                    blink(int(a[len(a)//2:]), num_blinks-1)
        else:
            return blink(stone_value*2024, num_blinks-1)

ans = 0
total_blinks = 75
for j in range(len(s)):
    ans += blink(s[j], total_blinks)
print("ans:", ans)
