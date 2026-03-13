
s = list(map(int, open(0).read().strip().split()))

def blink():
    i = 0
    while i in range(len(s)):
        if s[i] == 0: s[i] = 1
        elif len(str(s[i])) % 2 == 0:
            a = str(s[i])
            x = a[:len(a)//2]
            y = a[len(a)//2:]
            s[i] = int(x)
            s.insert(i+1, int(y))
            i += 1
        else:
            s[i] *= 2024
        i += 1


for i in range(25):
    print(i+1,"/",25, " length: ", len(s),sep="")
    blink()

print(len(s))
