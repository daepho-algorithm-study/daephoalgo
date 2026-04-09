import heapq

n, m = map(int, input().split())
graph = [list(map(int, input().strip())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = []
dist = [[[float("inf")] * 2 for _ in range(m)] for _ in range(n)]

dist[0][0][0] = 1
heapq.heappush(q, [1, 0, 0, 0])

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
                
            if graph[nx][ny] == 1 and broken < 1:
                newBroken = broken + 1
                if dist[nx][ny][newBroken] > cost + 1:
                    dist[nx][ny][newBroken] = cost + 1
                    heapq.heappush(q, [cost + 1, nx, ny, newBroken])
                
result = min(dist[n-1][m-1][0], dist[n-1][m-1][1])
print(-1 if result == float("inf") else result)