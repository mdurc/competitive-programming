
files = {}
blanks = []

pos = 0
file_index = 0
for i, c in enumerate(input()):
    x = int(c)
    if i%2 == 0:
        files[file_index] = (pos, x)
        file_index += 1
    else:
        if x != 0:
            blanks.append((pos,x))
    pos += x

while file_index > 0:
    file_index -= 1
    pos, length = files[file_index]
    for i, (p, l) in enumerate(blanks):
        if p<pos and l>=length:
            files[file_index] = (p, length)
            if l == length:
                blanks.pop(i)
            else:
                blanks[i] = (p+length, l-length)
            break

ans = 0
for fid, (pos, length) in files.items():
    for i in range(pos, pos+length):
        ans += fid*i

print("ans:", ans)
