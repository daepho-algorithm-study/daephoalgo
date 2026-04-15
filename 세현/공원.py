def solution(mats, park):
    w, h = len(park[0]), len(park)  # 가로 세로
    dp = [[0 for _ in range(w)] for _ in range(h)]  # dp 배열
    mx = -1 
    
    # 가장 자리부터 계산
    for i in range(w):
        if park[0][i] == '-1': dp[0][i] = 1 
    for i in range(h):
        if park[i][0] == '-1': dp[i][0] = 1
    
    for i in range(1, h):
        for j in range(1, w):
            
            # 비어있을 때
            if park[i][j] == '-1':
                
                # 왼쪽 전 칸, 위쪽 전칸, 대각선 전 칸을 보고 **가장 작은 값**에서 1을 더한 값이 현재 값
                # dp[i][j]가 크기 k짜리 정사각형이 되려면, 좌, 상, 좌상대각선의 만들 수 있는 정사각형 크기가 k-1 이상이어야 하기 때문
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
                
                mx = max(mx, dp[i][j])
    
    mats.sort(reverse=True)
    for mat in mats:
        if mat <= mx:
            return mat
    
    return -1