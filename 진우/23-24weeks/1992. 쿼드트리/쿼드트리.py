import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

# 최대 64×64 흑백 영상 정보를 저장하는 배열
# board[i][j] : (i, j) 위치의 값 (0 또는 1)
board = [[0] * 64 for _ in range(64)]

# 쿼드트리 압축 결과를 저장할 문자열
ans = ""


"""
(x, y)를 좌상단으로 하는 l × l 영역을 검사하여
쿼드트리 방식으로 문자열을 생성하는 함수

- 영역이 모두 같은 값이면 '0' 또는 '1' 추가
- 다른 값이 섞여 있으면
  '(' + 4개 영역 재귀 결과 + ')' 형태로 압축
"""
def check(x, y, l):
    global ans

    # 현재 영역의 기준 값 (좌상단)
    first_color = board[x][y]

    # 현재 l × l 영역이 모두 같은 값인지 확인
    for i in range(x, x + l):
        for j in range(y, y + l):
            # 기준 값과 다른 값이 하나라도 발견되면 분할
            if board[i][j] != first_color:
                ans += "("  # 분할 시작 표시

                k = l // 2  # 영역을 4등분할 크기

                # 4개의 사분면을 전위 순회(preorder) 방식으로 처리
                check(x, y, k)             # 왼쪽 위
                check(x, y + k, k)         # 오른쪽 위
                check(x + k, y, k)         # 왼쪽 아래
                check(x + k, y + k, k)     # 오른쪽 아래

                ans += ")"  # 분할 종료 표시
                return      # 현재 영역 처리는 종료

    # 여기까지 왔다는 것은 영역이 모두 같은 값이라는 뜻
    if first_color == 1:
        ans += "1"  # 모두 1인 영역
    else:
        ans += "0"  # 모두 0인 영역


# 영상의 한 변 길이 (2의 제곱수)
N = int(input())

# 영상 정보 입력 (문자열 → 정수 변환)
for i in range(N):
    s = input().strip()
    for j in range(N):
        board[i][j] = int(s[j])  # '0','1' → 0,1

# 전체 영역부터 쿼드트리 압축 시작
check(0, 0, N)

# 압축 결과 출력
print(ans)
