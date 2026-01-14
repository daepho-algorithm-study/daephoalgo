# 수열의 길이 입력
n = int(input())

# 수열 입력
arr = list(map(int, input().split()))

# dp[i] = i번째 원소에서 끝나는 최대 연속 부분합
dp = [0] * n

# 첫 번째 원소로 초기화
dp[0] = arr[0]

# 두 번째 원소부터 차례대로 dp 계산
for i in range(1, n):
    # 이전까지의 합에 현재 값을 더할지,
    # 아니면 현재 값부터 새로 시작할지 선택
    if dp[i - 1] + arr[i] > arr[i]:
        dp[i] = dp[i - 1] + arr[i]   # 이어서 더하는 게 더 큰 경우
    else:
        dp[i] = arr[i]              # 새로 시작하는 게 더 큰 경우

# 최종 최대 연속 부분합 출력
print(max(dp))
