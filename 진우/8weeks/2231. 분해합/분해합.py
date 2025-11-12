N = int(input())

result = 0

for i in range(1, N):
    num = i
    M = i
    
    while num > 0:
        M += num % 10
        num //= 10

    if M == N:
        result = i
        break

print(result)
