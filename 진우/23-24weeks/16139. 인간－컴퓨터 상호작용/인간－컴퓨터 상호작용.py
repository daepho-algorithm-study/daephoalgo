import sys
input = sys.stdin.readline

# 문자열 입력
S = input().strip()                 
n = len(S)                  # 문자열 길이

# dp[문자][인덱스] 배열 생성
# dp[c][i] = 0 ~ i-1까지 문자 c 등장 횟수
dp = [[0] * (n + 1) for _ in range(26)]  # 26글자 알파벳, 길이 n+1

# 누적합 전처리
for c in range(26):                 # 각 알파벳 문자 c (0:a, 1:b, ...)
    for i in range(n):              # 문자열 전체 순회
        dp[c][i + 1] = dp[c][i]    # 이전까지 누적값 그대로 복사
        
        # 현재 문자 S[i]가 c이면 +1
        if ord(S[i]) - ord('a') == c:
            dp[c][i + 1] += 1

# 쿼리 개수 입력
q = int(input())

# 각 쿼리 처리
for _ in range(q):
    c, l, r = input().split()       # 문자 c, 구간 [l, r]
    l, r = int(l), int(r)           # 문자열 인덱스로 변환
    
    i = ord(c) - ord('a')           # 문자 → 0~25 인덱스
    
    # 구간 [l, r]에서 문자 c의 개수
    # dp[i][r + 1] = 0 ~ r까지의 누적합
    # dp[i][l] = 0 ~ l-1까지의 누적합
    print(dp[i][r + 1] - dp[i][l])
