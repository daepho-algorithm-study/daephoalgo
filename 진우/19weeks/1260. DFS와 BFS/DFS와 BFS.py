import sys
from collections import deque

input = sys.stdin.readline

# 인접 리스트: 각 정점에 연결된 정점 목록
arr = [[] for _ in range(1001)]

# DFS 방문 여부 체크 배열
dfs_visited = [False] * 1001

# BFS 방문 여부 체크 배열
bfs_visited = [False] * 1001


# 깊이 우선 탐색(DFS)
def dfs(v):
    # 현재 정점을 방문 처리
    dfs_visited[v] = True

    # 방문한 정점 출력
    print(v, end=' ')

    # 현재 정점과 연결된 모든 정점 탐색
    for nxt in arr[v]:
        # 아직 방문하지 않았다면 재귀 호출
        if not dfs_visited[nxt]:
            dfs(nxt)


# 너비 우선 탐색(BFS)
def bfs(v):
    q = deque()

    # 시작 정점을 큐에 삽입
    q.append(v)
    bfs_visited[v] = True

    # 큐가 빌 때까지 반복
    while q:
        node = q.popleft()

        # 현재 정점 출력
        print(node, end=' ')

        # 현재 정점과 연결된 모든 정점 탐색
        for nxt in arr[node]:
            # 아직 방문하지 않았다면 큐에 삽입
            if not bfs_visited[nxt]:
                bfs_visited[nxt] = True
                q.append(nxt)


# 입력 처리
N, M, V = map(int, input().split())

# 간선 정보 입력 (양방향 그래프)
for _ in range(M):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

# 작은 번호부터 방문하기 위해 정렬
for i in range(1, N + 1):
    arr[i].sort()

# DFS 수행 및 출력
dfs(V)
print()

# BFS 수행 및 출력
bfs(V)
print()
