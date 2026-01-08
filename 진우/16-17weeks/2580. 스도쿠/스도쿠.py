import sys
input = sys.stdin.readline

# 스도쿠 판 (9x9)
board = [list(map(int, input().split())) for _ in range(9)]

# 빈 칸(0)의 좌표를 저장하는 리스트
# 각 원소는 (row, col)
blank = []

# 빈칸 좌표 수집
for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            blank.append((i, j))

def check(row, col, num):
    """
    (row, col)에 num을 놓을 수 있는지 검사하는 함수
    1) 같은 행에 num이 있는지
    2) 같은 열에 num이 있는지
    3) 같은 3x3 박스에 num이 있는지
    """

    # 같은 행(row) 검사
    for j in range(9):
        if board[row][j] == num:
            return False

    # 같은 열(col) 검사
    for i in range(9):
        if board[i][col] == num:
            return False

    # 3x3 박스의 시작 좌표 계산
    nx = (row // 3) * 3
    ny = (col // 3) * 3

    # 3x3 박스 내부 검사
    for i in range(nx, nx + 3):
        for j in range(ny, ny + 3):
            if board[i][j] == num:
                return False

    # 위 조건을 모두 통과하면 배치 가능
    return True


def sudoku(n):
    """
    백트래킹으로 스도쿠를 해결하는 함수
    n : 현재 채울 빈칸의 인덱스
    """

    # 모든 빈칸을 다 채운 경우 → 정답 완성
    if n == len(blank):
        for i in range(9):
            print(*board[i])
        sys.exit(0)  # 정답은 하나이므로 즉시 종료

    # 현재 빈칸의 좌표
    r, c = blank[n]

    # 1~9를 하나씩 시도
    for num in range(1, 10):
        # (r, c)에 num을 놓을 수 있다면
        if check(r, c, num):
            board[r][c] = num     # 숫자 배치
            sudoku(n + 1)         # 다음 빈칸으로 진행
            board[r][c] = 0       # 백트래킹 (원상 복구)

# 스도쿠 해결 시작
sudoku(0)
