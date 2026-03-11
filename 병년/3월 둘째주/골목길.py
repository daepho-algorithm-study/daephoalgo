from collections import deque

N, M = map(int, input().split())
edge = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edge.append([a,b,-c])

INF = float('inf')
dist = [INF for _ in range(N + 1)]
queue = deque()
visited = [False for _ in range(N + 1)]
parent = [-1] * (N + 1)

def bellman_ford(start):
    dist[start] = 0
    for _ in range(N - 1) :
        for s, e, cost in edge:
            if dist[s] != INF and dist[e] > dist[s] + cost :
                dist[e] = dist[s] + cost
                parent[e] = s
    for s, e, cost in edge:
        if dist[s] != INF and dist[e] > dist[s] + cost:
            queue.append(e)
            visited[e] = True


def bfs():
    while queue:
        now = queue.popleft()
        if now == N:
            return True
        for s,e,_ in edge:
            if s == now:
                if not visited[e]:
                    visited[e] = True
                    queue.append(e)
    return False
bellman_ford(1)
if bfs():
    print(-1)
else :
    path = []
    cur = N
    while cur != -1:
        path.append(cur)
        cur = parent[cur]
    print(*reversed(path))