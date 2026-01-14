import sys
input = sys.stdin.readline

# dp[i][j] : i번째 집을 j색으로 칠했을 때의 최소 누적 비용
# j = 0 (R), 1 (G), 2 (B)
dp = [[0] * 3 for _ in range(1001)]

N = int(input())  # 집의 개수 입력

# 각 집을 R, G, B로 칠하는 비용 입력
for i in range(N):
    dp[i][0], dp[i][1], dp[i][2] = map(int, input().split())

# DP 계산
for i in range(1, N):
    # i번째 집을 빨강으로 칠할 경우
    # 이전 집은 초록 또는 파랑만 가능
    dp[i][0] += min(dp[i - 1][1], dp[i - 1][2])

    # i번째 집을 초록으로 칠할 경우
    # 이전 집은 빨강 또는 파랑만 가능
    dp[i][1] += min(dp[i - 1][0], dp[i - 1][2])

    # i번째 집을 파랑으로 칠할 경우
    # 이전 집은 빨강 또는 초록만 가능
    dp[i][2] += min(dp[i - 1][0], dp[i - 1][1])

# 마지막 집에서 R, G, B 중 최소 비용 선택
mn = dp[N - 1][0]

if mn > dp[N - 1][1]:
    mn = dp[N - 1][1]

if mn > dp[N - 1][2]:
    mn = dp[N - 1][2]

# 최소 비용 출력
print(mn)
