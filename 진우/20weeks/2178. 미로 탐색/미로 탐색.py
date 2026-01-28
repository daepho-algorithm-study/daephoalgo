from collections import deque

N, M = map(int, input().split())

# 미로 정보 (1: 길, 0: 벽)
arr = [list(map(int, input().strip())) for _ in range(N)]

# 방문 여부 + 최단 거리 저장 (0이면 미방문)
visited = [[0] * M for _ in range(N)]

def bfs(r, c):
    # 상, 우, 하, 좌 방향 이동
    nx = [-1, 0, 1, 0]
    ny = [0, 1, 0, -1]

    q = deque()

    # 시작 위치 방문 처리 (거리 = 1)
    visited[r][c] = 1
    q.append((r, c))

    while q:
        x, y = q.popleft()

        # 4방향 탐색
        for i in range(4):
            nr = x + nx[i]
            nc = y + ny[i]

            # 미로 범위 밖이면 무시
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                continue

            # 벽이거나 이미 방문한 칸이면 무시
            if arr[nr][nc] == 0 or visited[nr][nc] != 0:
                continue

            # 이동 가능하면 거리 갱신
            visited[nr][nc] = visited[x][y] + 1

            # 큐에 다음 위치 추가
            q.append((nr, nc))


# (0,0)에서 BFS 시작
bfs(0, 0)

# 도착 지점까지의 최단 거리 출력
print(visited[N-1][M-1])
