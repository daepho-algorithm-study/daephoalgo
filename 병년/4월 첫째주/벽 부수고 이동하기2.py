import heapq

n, m, K = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

graph = [list(map(int, input().strip())) for _ in range(n)]
dist = [[[float("inf")for _ in range(K + 1)] for _ in range(m)] for _ in range(n)]


q = []
dist[0][0][0] = 1
heapq.heappush(q, [1,0,0,0])


while q :
    cost, x, y, broken = heapq.heappop(q)
    if dist[x][y][broken] < cost:
        continue
    
    for k in range(4):
        nx, ny = x + dx[k], y + dy[k]
        if 0 <= nx < n and 0 <= ny < m:
            if graph[nx][ny] == 0:
                if dist[nx][ny][broken] > cost + 1:
                    dist[nx][ny][broken] = cost + 1
                    heapq.heappush(q, [cost + 1, nx, ny, broken])
            elif graph[nx][ny] == 1 and broken < K:
                newBroken = broken + 1
                if dist[nx][ny][newBroken] > cost + 1:
                    dist[nx][ny][newBroken] = cost + 1
                    heapq.heappush(q, [cost + 1, nx, ny, newBroken])

result = float("inf")
for k in range(K + 1):
    if dist[n - 1][m - 1][k] < result:
        result = dist[n - 1][m - 1][k]
                
print(-1 if result == float("inf") else result)