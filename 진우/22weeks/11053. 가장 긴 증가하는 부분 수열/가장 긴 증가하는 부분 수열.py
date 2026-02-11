# 입력 수열
A = [0] * 1001
dp = [0] * 1001  # i번째까지 끝나는 LIS 길이를 저장

# 입력
N = int(input())                # 수열 길이 입력
arr = list(map(int, input().split()))  # 수열 요소 입력

for i in range(N):
    A[i] = arr[i]

# dp 계산
for i in range(N):
    dp[i] = 1  # 최소 LIS 길이 = 1 (자기 자신만 포함)

    # i번째 이전의 모든 원소와 비교
    for j in range(i):
        if A[i] > A[j]:  # 증가 조건
            dp[i] = max(dp[i], dp[j] + 1)  # j에서 끝나는 LIS에 i를 붙인 길이와 현재 dp[i] 비교

# LIS 최대 길이 찾기
mx = max(dp[:N])

print(mx)  # LIS 길이 출력
