

disk = []
file = 0
for i, c in enumerate(input()):
    x = int(c)
    if i % 2 == 0:
        disk += [file]*x
        file += 1
    else:
        disk += [-1]*x

blanks = [i for i in range(len(disk)) if disk[i] == -1]

for i in blanks:
    while disk[-1] == -1: disk.pop()
    if i >= len(disk): break
    disk[i] = disk.pop()

print(sum(i * x for i, x in enumerate(disk)))
