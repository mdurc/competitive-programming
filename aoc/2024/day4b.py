s = open("in.txt").read().strip().split("\n")
s = [list(x) for x in s]

ans = 0
row_len = len(s)
col_len = len(s[0])

for i in range(1, row_len-1):
    for j in range(1, col_len-1):
        if s[i][j]!="A": continue
        corners = [s[i-1][j-1], s[i-1][j+1], s[i+1][j-1], s[i+1][j+1]]
        a = corners[0] + corners[-1]
        b = corners[1] + corners[2]
        if a == "MS" or a == "SM":
            if b == "MS" or b == "SM":	
                ans += 1

print("ans:", ans)


"""
# first solution
key = ['M', 'A', 'S']

def eq(a, key):
    return a==key or a==list(reversed(key))

for i in range(row_len):
    for j in range(col_len):
        m = []
        if j+2 < col_len and i+2 < row_len:
            # right diag
            m.append(s[i][j])
            m.append(s[i+1][j+1])
            m.append(s[i+2][j+2])
            if eq(m, key):
                m.clear()
                # left diag
                m.append(s[i][j+2])
                m.append(s[i+1][j+1])
                m.append(s[i+2][j])
                if eq(m, key):
                    ans+=1
            m.clear()
print("ans:", ans)
"""
