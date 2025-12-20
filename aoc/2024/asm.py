A = 4
B = A % 8
B = B ^ 4
C = A >> B
B = B ^ C
B = B ^ 4
print(B%8)
