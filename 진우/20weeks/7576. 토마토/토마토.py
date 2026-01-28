import sys
from collections import deque

input = sys.stdin.readline

# 입력: M(가로), N(세로)
M, N = map(int, input().split())

# 토마토 상태 저장
# -1: 토마토 없음, 0: 안 익음, 1 이상: 익은 날짜
box = [list(map(int, input().split())) for _ in range(N)]

# BFS를 위한 큐
q = deque()

# 상, 좌, 하, 우 방향
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

# 이미 익은 토마토를 BFS 시작점으로 큐에 넣기
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            q.append((i, j))


def bfs():
    while q:
        x, y = q.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            # 범위 체크
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue

            # 아직 익지 않은 토마토만 전파
            if box[nx][ny] == 0:
                box[nx][ny] = box[x][y] + 1
                q.append((nx, ny))


# BFS 실행
bfs()

# 결과 계산
mx = 0
for i in range(N):
    for j in range(M):
        # 안 익은 토마토가 남아있으면 실패
        if box[i][j] == 0:
            print(-1)
            sys.exit(0)
        mx = max(mx, box[i][j])

# 시작 날짜가 1이므로 -1
print(mx - 1)
