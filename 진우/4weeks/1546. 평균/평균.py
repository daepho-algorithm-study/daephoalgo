N = int(input())

arr = list(map(int, input().split()))

M = max(arr)

score = sorted(arr)

avg = 0

for i in range(N):
    avg += score[i] / M * 100

print(avg/N)
