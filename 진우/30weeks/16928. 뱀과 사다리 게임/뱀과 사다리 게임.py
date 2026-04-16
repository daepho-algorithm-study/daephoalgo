from collections import deque

# 사다리/뱀 정보 저장
# board[x] = y → x에 도착하면 y로 이동
board = [0] * 101

# 각 칸까지 도달하는 최소 주사위 횟수
# -1이면 아직 방문하지 않음
visited = [-1] * 101


# BFS로 최소 이동 횟수 탐색
def bfs(start):
    q = deque()
    q.append(start)

    # 시작 위치는 이동 횟수 0
    visited[start] = 0

    while q:
        cur = q.popleft()

        # 100번 칸 도달 시 종료 (최소 횟수 보장)
        if cur == 100:
            return

        # 주사위 1~6까지 모든 경우 탐색
        for i in range(1, 7):
            move = cur + i

            # 100번 초과하면 이동 불가
            if move > 100:
                continue

            # 사다리 또는 뱀이 있으면 이동
            if board[move] != 0:
                move = board[move]

            # 아직 방문하지 않은 칸이면
            if visited[move] == -1:
                # 현재까지 횟수 + 1 (주사위 한 번 사용)
                visited[move] = visited[cur] + 1

                # 다음 탐색을 위해 큐에 추가
                q.append(move)


# 입력 처리
N, M = map(int, input().split())

# 사다리 + 뱀 정보 입력
for _ in range(N + M):
    x, y = map(int, input().split())
    board[x] = y

# BFS 시작 (1번 칸)
bfs(1)

# 100번 칸까지 최소 이동 횟수 출력
print(visited[100])