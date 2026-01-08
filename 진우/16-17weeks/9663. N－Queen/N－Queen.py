import sys
input = sys.stdin.readline

# 체스판 크기 (N x N)
N = int(input())

# 가능한 N-Queen 배치 개수
cnt = 0

# board[row] = 해당 row에 놓인 퀸의 column
board = [0] * N


def check(row):
    """
    현재 row에 놓은 퀸이
    이전 행(0 ~ row-1)에 놓인 퀸들과
    충돌하는지 검사하는 함수
    """
    for i in range(row):
        # 같은 열과 대각선에 퀸이 있는 경우
        if board[row] == board[i] or abs(board[row] - board[i]) == row - i:
            return False

    # 위 조건에 모두 걸리지 않으면 안전한 위치
    return True


def queen(row):
    """
    DFS + 백트래킹
    row번째 행에 퀸을 배치하는 함수
    """
    global cnt

    # 기저 조건
    # 모든 행(0 ~ N-1)에 퀸을 배치 완료한 경우
    if row == N:
        cnt += 1      # 하나의 완성된 경우의 수
        return

    # 현재 행(row)에 대해 모든 열(col)을 하나씩 시도
    for col in range(N):
        # (row, col)에 퀸을 놓아본다
        board[row] = col

        # 이전 행들과 충돌하지 않는다면
        if check(row):
            # 다음 행으로 이동
            queen(row + 1)

# 0번째 행부터 퀸 배치 시작
queen(0)

# 가능한 배치 개수 출력
print(cnt)
