import sys
input = sys.stdin.readline

# dp[i] : 돌이 i개 남아 있을 때 필요한 최소 턴 수
dp = [0] * 1001

# 돌의 개수 입력
N = int(input())

"""
초기값 설정 (기저 상태)

돌이 1개 → 1턴
돌이 2개 → 2턴 (1개씩 두 번)
돌이 3개 → 1턴 (3개 한 번에 제거)
"""
dp[1] = 1
dp[2] = 2
dp[3] = 1

"""
i개의 돌이 있을 때

가능한 행동
1) 돌 1개 제거 → dp[i-1]
2) 돌 3개 제거 → dp[i-3]

둘 중 더 적은 턴을 선택
+ 현재 턴 1 추가
"""
for i in range(4, N + 1):
    dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1)

"""
게임은 SK부터 시작

총 턴 수가
홀수 → SK 승리
짝수 → CY 승리
"""
if dp[N] % 2 == 1:
    print("SK")
else:
    print("CY")