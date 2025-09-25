N, M = map(int, input().split())

box = [0] * N

for tc in range(M):
    arr = list(map(int, input().split()))
    i = arr[0]
    j = arr[1]
    k = arr[2]

    for idx in range(i -1, j):
        box[idx] = k

print(*box)
