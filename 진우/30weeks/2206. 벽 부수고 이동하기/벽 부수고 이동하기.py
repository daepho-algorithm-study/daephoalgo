from collections import deque

# N x M 미로 크기
N, M = map(int, input().split())

# 미로 정보 (0-based 인덱스)
board = [list(map(int, list(input().strip()))) for _ in range(N)]

# visited[x][y][wall]: 벽 부순 여부까지 포함한 방문 거리
visited = [[[0] * 2 for _ in range(M)] for _ in range(N)]

# 상, 우, 하, 좌
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def bfs():
    q = deque()
    q.append((0, 0, 0))  # 시작점 (0,0), 벽 안 부숨
    visited[0][0][0] = 1

    while q:
        x, y, wall = q.popleft()

        if x == N-1 and y == M-1:
            return visited[x][y][wall]

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                # 빈 칸 이동
                if board[nx][ny] == 0 and visited[nx][ny][wall] == 0:
                    visited[nx][ny][wall] = visited[x][y][wall] + 1
                    q.append((nx, ny, wall))

                # 벽 부수기 (한 번만 가능)
                if board[nx][ny] == 1 and wall == 0 and visited[nx][ny][1] == 0:
                    visited[nx][ny][1] = visited[x][y][wall] + 1
                    q.append((nx, ny, 1))

    return -1

print(bfs())