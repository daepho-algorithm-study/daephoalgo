from collections import deque

# 시작 위치 N, 목표 위치 K 입력
N, K = map(int, input().split())

# visited[x] = x 위치까지 도달하는 데 걸린 최소 시간
# -1이면 아직 방문하지 않은 상태
visited = [-1] * 100001

def bfs(start):
    q = deque()

    # 시작 위치 방문 처리 (시간 0)
    visited[start] = 0
    q.append(start)

    while q:
        x = q.popleft()

        # 목표 위치에 도착하면 즉시 종료
        # BFS 특성상 이때의 시간이 최단 시간
        if x == K:
            return

        # x - 1 로 이동
        if x - 1 >= 0 and visited[x - 1] == -1:
            visited[x - 1] = visited[x] + 1
            q.append(x - 1)

        # x + 1 로 이동
        if x + 1 <= 100000 and visited[x + 1] == -1:
            visited[x + 1] = visited[x] + 1
            q.append(x + 1)

        # x * 2 로 순간 이동
        if 2 * x <= 100000 and visited[2 * x] == -1:
            visited[2 * x] = visited[x] + 1
            q.append(2 * x)

# BFS 실행
bfs(N)

# 목표 위치까지 걸린 최단 시간 출력
print(visited[K])
