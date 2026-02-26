import sys
input = sys.stdin.readline

# N: 배열 크기 (N x N), M: 구간 합을 물어보는 쿼리 개수
N, M = map(int, input().split())

# 원본 배열 입력 (0-based index)
# arr[i][j] : i행 j열의 값
arr = [list(map(int, input().split())) for _ in range(N)]

# 누적합 배열 dp (1-based index)
# dp[i][j] : (1,1)부터 (i,j)까지의 직사각형 합
# 편의를 위해 0번째 행, 0번째 열은 모두 0으로 둔다
dp = [[0] * (N + 1) for _ in range(N + 1)]

# 누적합 전처리
for i in range(1, N + 1):
    for j in range(1, N + 1):
        dp[i][j] = (
            dp[i - 1][j]          # 위쪽 직사각형 합
            + dp[i][j - 1]        # 왼쪽 직사각형 합
            - dp[i - 1][j - 1]    # 위+왼쪽에서 중복으로 더해진 영역 제거
            + arr[i - 1][j - 1]   # 현재 칸의 값 추가 (0-based → 1-based 보정)
        )

# 쿼리 처리
# (x1, y1)부터 (x2, y2)까지의 부분합 계산
for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())

    # 구간 합 공식
    # 전체(x2,y2) - 위쪽 - 왼쪽 + 겹친 영역
    ans = (
        dp[x2][y2]
        - dp[x1 - 1][y2]
        - dp[x2][y1 - 1]
        + dp[x1 - 1][y1 - 1]
    )

    print(ans)
