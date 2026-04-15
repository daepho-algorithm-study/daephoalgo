import heapq
m, n = map(int, input().split(" "))

graph = [list(map(int, input().strip())) for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dijkstra () :
    q = []
    heapq.heappush(q, [0, 0, 0])

    dist = [[float("inf")] * m for _ in  range(n)]
    dist[0][0] = 0

    while q :
        cost, x, y= heapq.heappop(q)

        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < n and 0 <= ny < m:
                newcost = graph[nx][ny] + cost
                if dist[nx][ny] > newcost :
                    dist[nx][ny] = newcost
                    heapq.heappush(q, [newcost, nx, ny])
    return dist


# def bfs():
#     while deq:
#         x, y, cost= deq.popleft()
#         if visited[x][y] < cost:
#             continue
#         for k in range(4):
#             nx, ny = x + dx[k], y + dy[k]
#             if 0 <= nx < n and 0 <= ny < m:
#                 if graph[nx][ny] == 1:
#                     if visited[nx][ny] > cost + 1:
#                         visited[nx][ny] = cost + 1
#                         deq.append([nx, ny, cost + 1, ])
#                 else :
#                     if visited[nx][ny] > cost:
#                         visited[nx][ny] = cost
#                         deq.appendleft([nx, ny, cost])
# bfs()
# print(visited[n - 1][m - 1])
dist = dijkstra()
print(dist[n - 1][m - 1])
