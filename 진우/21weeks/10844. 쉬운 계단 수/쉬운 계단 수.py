import sys
input = sys.stdin.readline

MOD = 1000000000

N = int(input())

# dp[i][j] : 길이가 i이고 마지막 자리가 j인 계단 수의 개수
dp = [[0] * 10 for _ in range(N + 1)]

# ===============================
# 초기값 설정 (길이 1)
# ===============================
for j in range(1, 10):
    dp[1][j] = 1
dp[1][0] = 0

# ===============================
# DP 계산 (길이 2부터 N까지)
# ===============================
for i in range(2, N + 1):
    for j in range(10):
        if j == 0:
            dp[i][j] = dp[i - 1][1] % MOD
        elif j == 9:
            dp[i][j] = dp[i - 1][8] % MOD
        else:
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD

# ===============================
# 길이가 N인 계단 수의 총 개수 계산
# ===============================
result = sum(dp[N]) % MOD
print(result)
