import sys

input = sys.stdin.readline  # 입력 속도 향상

N = int(input())  # 사람 수 입력

# 각 사람이 돈을 인출하는 데 걸리는 시간 입력
arr = list(map(int, input().split()))

# 인출 시간이 짧은 사람부터 처리하기 위해 오름차순 정렬
arr.sort()

dp = [0] * N
dp[0] = arr[0]  # 첫 번째 사람의 대기 시간

# dp[i] = i번째 사람까지의 누적 대기 시간
for i in range(1, N):
    dp[i] = dp[i - 1] + arr[i]

result = 0
# 모든 사람의 대기 시간을 합산
for time in dp:
    result += time

# 최소 대기 시간의 총합 출력
print(result)
