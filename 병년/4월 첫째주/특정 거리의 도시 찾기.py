import heapq

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]

dist = [float("inf")] * (n + 1)

for _ in range(m) :
    a, b = map(int, input().split())
    graph[a].append((1, b))


def dijkstra (start) :
    q = []
    heapq.heappush(q, [0, start])
    dist[start] = 0
    while q:
        cur, now = heapq.heappop(q)
        if cur > dist[now]:
            continue
        for cost, nxt in graph[now]:
            nxtCost = cost + cur
            if nxtCost < dist[nxt]:
                dist[nxt] = nxtCost
                heapq.heappush(q, [nxtCost, nxt])

dijkstra(x)      
result = []
for i in range(len(dist)) :
    if dist[i] == k:
        result.append(i)
if len(result) == 0:
    print(-1)
for num in result :
    print(num)
    
    

