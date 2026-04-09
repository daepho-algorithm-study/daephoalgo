import heapq
idx = 1

while True:
    n = int(input())
    if n == 0:
        break
    graph = [list(map(int, input().split(" "))) for _ in range(n)]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def dijkstra () :
        q = []
        dist = [[float("inf")] * n for _ in range(n)]
        
        dist[0][0] = graph[0][0]
        heapq.heappush(q, [dist[0][0], 0, 0])

        while q :
            cost, x, y = heapq.heappop(q)
            if dist[x][y] < cost:
                continue

            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < n and 0 <= ny < n:
                    newcost = graph[nx][ny] + cost
                    if dist[nx][ny] > newcost:
                        dist[nx][ny] = newcost
                        heapq.heappush(q, [newcost, nx, ny])
        return dist
    dist = dijkstra()
    print(f'Problem {idx}: {dist[n - 1][n - 1]}')
    idx+=1
