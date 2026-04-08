import heapq
n, m = map(int, input().split())

q = []
heapq.heappush(q, [0, n])
dist = [float("inf")] * 100001
dist[n] = 0
while q:
    cost, now = heapq.heappop(q)
    if cost > dist[now] :
        continue
    
    for nxt in [now * 2, now - 1, now + 1]:
        if 0 <= nxt and nxt <= 100000:
            if nxt == now * 2:
                newcost = cost
            else:
                newcost = cost + 1
            if newcost < dist[nxt] :
                dist[nxt] = newcost
                heapq.heappush(q, [newcost, nxt])
                
                
print(dist[m])