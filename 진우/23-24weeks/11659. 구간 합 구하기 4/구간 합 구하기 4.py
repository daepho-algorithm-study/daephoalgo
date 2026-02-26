# 입력 속도 최적화
import sys
input = sys.stdin.readline

# N: 수의 개수, M: 구간 합 질의 개수
N, M = map(int, input().split())

# 원본 배열 (1번 인덱스부터 사용, 0번은 편의상 0)
arr = [0] + list(map(int, input().split()))

# 누적 합 배열
dp = [0] * (N + 1)
for i in range(1, N + 1):
    dp[i] = dp[i - 1] + arr[i]

# M개의 구간 합 질의 처리
for _ in range(M):
    a, b = map(int, input().split())
    print(dp[b] - dp[a - 1])
