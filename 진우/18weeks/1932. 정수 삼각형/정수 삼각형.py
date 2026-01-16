import sys
input = sys.stdin.readline

# dp[i][j] : i번째 줄 j번째 숫자까지 내려왔을 때의 최대 누적 합
dp = [[0] * 501 for _ in range(501)]

N = int(input())  # 삼각형의 높이 입력

# 삼각형 숫자 입력
# dp 배열에 그대로 저장
for i in range(1, N + 1):
    nums = list(map(int, input().split()))
    for j in range(1, i + 1):
        dp[i][j] = nums[j - 1]

# DP 계산 (두 번째 줄부터)
for i in range(2, N + 1):
    for j in range(1, i + 1):
        # 왼쪽 위(dp[i-1][j-1])와 오른쪽 위(dp[i-1][j]) 중 큰 값 선택
        dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j])

# 마지막 줄에서 최대값 찾기
mx = -999999  # 충분히 작은 값으로 초기화

for i in range(1, N + 1):
    if mx < dp[N][i]:
        mx = dp[N][i]

# 결과 출력
print(mx)
