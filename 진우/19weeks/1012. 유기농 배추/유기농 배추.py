import sys
from collections import deque

input = sys.stdin.readline

# BFS로 하나의 배추 군집(연결된 배추 묶음) 탐색
def bfs(sr, sc):
    q = deque()
    q.append((sr, sc))
    visited[sr][sc] = True

    # 상, 하, 좌, 우 이동 방향
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    while q:
        r, c = q.popleft()

        for i in range(4):
            nr = r + dx[i]
            nc = c + dy[i]

            # 배추밭 범위 체크 (세로 N, 가로 M)
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                continue

            # 아직 방문하지 않았고 배추가 있다면 큐에 추가
            if not visited[nr][nc] and arr[nr][nc] == 1:
                visited[nr][nc] = True
                q.append((nr, nc))


T = int(input())  # 테스트 케이스 수

for _ in range(T):
    # 배추밭 크기(M: 가로, N: 세로), 배추 개수
    M, N, K = map(int, input().split())

    # 배추밭 정보 초기화
    arr = [[0] * M for _ in range(N)]
    visited = [[False] * M for _ in range(N)]

    # 배추 위치 입력 (X, Y) → arr[Y][X]
    for _ in range(K):
        X, Y = map(int, input().split())
        arr[Y][X] = 1

    cnt = 0  # 필요한 지렁이 수 = 배추 군집 개수

    # 배추밭 전체 탐색
    for i in range(N):
        for j in range(M):
            # 방문하지 않았고 배추가 있다면 새로운 군집 시작
            if not visited[i][j] and arr[i][j] == 1:
                bfs(i, j)   # 해당 군집 BFS 탐색
                cnt += 1   # 군집 하나 발견

    print(cnt)
