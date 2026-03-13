
s = open("in.txt").read().strip().split("\n")
s = [list(x) for x in s]

ans = 0
row_len = len(s)
col_len = len(s[0])

for i in range(row_len):
    for j in range(col_len):
        if s[i][j] != "X": continue
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                if dr == dc == 0: continue
                if not(0<=i+3*dr<row_len and 0<=j+3*dc<col_len): continue
                if s[i+dr][j+dc]=="M" and s[i+2*dr][j+2*dc]=="A" and s[i+3*dr][j+3*dc]=="S":
                    ans += 1

print("ans:", ans)

"""
#first solution
key = ['X', 'M', 'A', 'S']

def eq(a, key):
    return a==key or a==list(reversed(key))

for i in range(row_len):
    for j in range(col_len):
        m = []
        if j+3 < col_len:
            # right
            m.append(s[i][j])
            m.append(s[i][j+1])
            m.append(s[i][j+2])
            m.append(s[i][j+3])
            if eq(m, key):
                ans+=1
            m.clear()
            if i+3 < row_len:
                # right diag
                m.append(s[i][j])
                m.append(s[i+1][j+1])
                m.append(s[i+2][j+2])
                m.append(s[i+3][j+3])
                if eq(m, key):
                    ans+=1
                m.clear()
        if i+3 < row_len:
            # left
            m.append(s[i][j])
            m.append(s[i+1][j])
            m.append(s[i+2][j])
            m.append(s[i+3][j])
            if eq(m, key):
                ans+=1
            m.clear()
            if j-3 >= 0:
                # left diag
                m.append(s[i][j])
                m.append(s[i+1][j-1])
                m.append(s[i+2][j-2])
                m.append(s[i+3][j-3])
                if eq(m, key):
                    ans+=1
                m.clear()
print("ans:", ans)
"""
