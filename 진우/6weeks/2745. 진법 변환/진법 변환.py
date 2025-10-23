N, B = input().split()
B = int(B)

result = 0
power = 1  # B^0

# 뒤에서부터 계산
for i in range(len(N) - 1, -1, -1):
    c = N[i]
    if 'A' <= c <= 'Z':
        num = ord(c) - ord('A') + 10
    else:
        num = ord(c) - ord('0')
    
    result += num * power
    power *= B

print(result)
