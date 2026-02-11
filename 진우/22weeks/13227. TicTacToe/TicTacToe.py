import sys
input = sys.stdin.readline

# 3x3 틱택토 판 입력
arr = [list(input().strip()) for _ in range(3)]

# 가로 / 세로 검사
for i in range(3):
    # 가로 검사
    if arr[i][0] != '.' and arr[i][0] == arr[i][1] == arr[i][2]:
        print("YES")
        exit()

    # 세로 검사
    if arr[0][i] != '.' and arr[0][i] == arr[1][i] == arr[2][i]:
        print("YES")
        exit()

# 대각선 (왼쪽 위 → 오른쪽 아래)
if arr[0][0] != '.' and arr[0][0] == arr[1][1] == arr[2][2]:
    print("YES")
    exit()

# 대각선 (오른쪽 위 → 왼쪽 아래)
if arr[0][2] != '.' and arr[0][2] == arr[1][1] == arr[2][0]:
    print("YES")
    exit()

print("NO")
