N = int(input())

x = []
y = []

for _ in range(N):
    a, b = map(int, input().split())
    
    x.append(a)
    y.append(b)

row = 0
col = 0

if N >= 2:
    row = max(x) - min(x)
    col = max(y) - min(y)

print(row * col)