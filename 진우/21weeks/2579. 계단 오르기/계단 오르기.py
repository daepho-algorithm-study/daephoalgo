import sys
input = sys.stdin.readline

N = int(input())

floor = [0] * (N + 1)
for i in range(1, N + 1):
    floor[i] = int(input())

dp = [0] * (N + 1)

dp[1] = floor[1]

if N >= 2:
    dp[2] = floor[1] + floor[2]

if N >= 3:
    for i in range(3, N + 1):
        dp[i] = max(
            dp[i - 2] + floor[i],
            dp[i - 3] + floor[i - 1] + floor[i]
        )

print(dp[N])
