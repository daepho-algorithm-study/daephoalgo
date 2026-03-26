import sys
input = sys.stdin.readline

# 누적합 배열
# b[i][j] : (1,1) ~ (i,j)까지 B로 시작할 때 다시 칠해야 하는 개수
# w[i][j] : (1,1) ~ (i,j)까지 W로 시작할 때 다시 칠해야 하는 개수
b = [[0] * 2001 for _ in range(2001)]
w = [[0] * 2001 for _ in range(2001)]

N, M, K = map(int, input().split())

# 원본 체스판
board = [[''] * (M + 1)] + [[''] + list(input().strip()) for _ in range(N)]

# 입력 + 누적합 계산
for i in range(1, N + 1):
    for j in range(1, M + 1):

        # 기본 누적합 (위 + 왼쪽 - 겹치는 부분)
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]
        w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1]

        # 체스판 규칙 적용
        if (i + j) % 2 == 0:
            # B 시작 기준
            if board[i][j] != 'B':
                b[i][j] += 1
            # W 시작 기준
            if board[i][j] != 'W':
                w[i][j] += 1
        else:
            # 반대 색
            if board[i][j] != 'W':
                b[i][j] += 1
            if board[i][j] != 'B':
                w[i][j] += 1

# 최소 결과
result = 9999999

# K x K 부분 탐색
for i in range(1, N - K + 2):
    for j in range(1, M - K + 2):

        x1, y1 = i, j
        x2, y2 = i + K - 1, j + K - 1

        # 2차원 누적합으로 구간 합 계산
        B = b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1]
        W = w[x2][y2] - w[x1 - 1][y2] - w[x2][y1 - 1] + w[x1 - 1][y1 - 1]

        result = min(result, B, W)

# 출력
print(result)