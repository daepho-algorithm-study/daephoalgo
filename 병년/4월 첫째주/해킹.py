import heapq

t = int(input())

for tc in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    def dijkstra(start) :
        dist = [float("inf")] * (n + 1)
        q = []
        heapq.heappush(q, (0, start))
        dist[start] = 0
        
        while q :
            cur, now = heapq.heappop(q)
            
            if dist[now] < cur:
                continue
            
            for nxt, cost in graph[now]:
                nxtCost = cur + cost
                if dist[nxt] > nxtCost:
                    dist[nxt] = nxtCost
                    heapq.heappush(q, (nxtCost, nxt))
        return dist
                    
    dist = dijkstra(c)
    count = 0
    mx = 0

    for i in range(1, n + 1):
        if dist[i] != float("inf"):
            count += 1
            mx = max(mx, dist[i])
    print(count, mx)