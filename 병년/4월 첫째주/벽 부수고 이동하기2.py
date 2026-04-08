from collections import deque
n, m, K = map(int, input().split())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

graph = [list(map(int, input().strip())) for _ in range(n)]
dist = [[[False for _ in range(K + 1)] for _ in range(m)] for _ in range(n)]


q = deque([(0, 0, 0, 1)])
dist[0][0][0] = 1

def bfs():
    while q :
        x, y, broken,depth = q.popleft()
        if x == n - 1 and y == m - 1:
            return depth
        
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] == 0:
                    if dist[nx][ny][broken] == False:
                        dist[nx][ny][broken] = True
                        q.append([nx, ny, broken, depth + 1])
                elif graph[nx][ny] == 1 and broken < K:
                    newBroken = broken + 1
                    if dist[nx][ny][newBroken] == False:
                        dist[nx][ny][newBroken] = True
                        q.append([nx, ny, newBroken, depth + 1])

result = bfs()
                
print(-1 if result == float("inf") else result)