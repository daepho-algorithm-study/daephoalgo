from collections import deque

# 입력
N = int(input())  # 노드 개수

# 각 노드의 인접 노드를 저장할 리스트 (1번부터 N번까지)
arr = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    arr[a].append(b)  # 무방향 그래프이므로 양쪽에 삽입
    arr[b].append(a)

visited = [False] * (N + 1)  # 방문 체크
parent = [0] * (N + 1)       # 부모 노드 저장

q = deque()
q.append(1)         # 루트 노드 1 삽입
visited[1] = True   # 루트 노드 방문 표시

# BFS
while q:
    node = q.popleft()  # 큐에서 현재 노드 꺼내기

    # 현재 노드의 모든 인접 노드 탐색
    for nxt in arr[node]:
        if not visited[nxt]:
            visited[nxt] = True     # 방문 표시
            parent[nxt] = node      # 부모 노드를 현재 노드로 기록
            q.append(nxt)           # 다음 탐색을 위해 큐에 삽입


# 부모 출력
for i in range(2, N + 1):
    print(parent[i])