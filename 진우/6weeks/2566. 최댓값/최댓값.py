arr = [list(map(int, input().split())) for _ in range(9)]

mx = -1
first = 0
second = 0

for i in range(9):
    for j in range(9):
       if arr[i][j] > mx:
           mx = arr[i][j]
           first = i + 1
           second = j + 1

print(mx)
print(first, second)