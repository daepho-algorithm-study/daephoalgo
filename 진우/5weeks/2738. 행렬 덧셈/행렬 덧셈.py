N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(2 * N)]

for i in range(N):
    for j in range(M):
        result = arr[i][j] + arr[i + N][j]
        print(result, end=' ')
    print()
