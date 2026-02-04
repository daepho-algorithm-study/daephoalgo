import sys
input = sys.stdin.readline

N = int(input())

# dp[i] : i를 1로 만드는 최소 연산 횟수
dp = [0] * (N + 1)

dp[1] = 0  # base case

for i in range(2, N + 1):
    # 1을 빼는 경우 (항상 가능)
    dp[i] = dp[i - 1] + 1

    # 2로 나누는 경우
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i // 2] + 1)

    # 3으로 나누는 경우
    if i % 3 == 0:
        dp[i] = min(dp[i], dp[i // 3] + 1)

print(dp[N])
