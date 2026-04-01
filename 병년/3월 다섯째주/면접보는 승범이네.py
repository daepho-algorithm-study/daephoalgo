import heapq

n, m, k = map(int, input().split(" "))


results = []

graph = [[] for _ in range(n)]


for _ in range(m):
    a, b, c = (map(int, input().split(" ")))
    graph[b - 1].append([a-1, c])

dist = [float("inf") for _ in range(n)]

myun = list(map(int, input().split(" ")))

def dijkstra() :
    q = []
    for m in myun:
        dist[m - 1] = 0
        heapq.heappush(q, [0, m - 1])
    
    while q :        
        cur, now = heapq.heappop(q)
        
        if dist[now] < cur :
            continue
        for [next, cost] in graph[now] :
            nextDist = cur + cost
            if nextDist < dist[next] :
                dist[next] = nextDist
                heapq.heappush(q, [nextDist, next])
                
dijkstra()
mx = max(dist)
for i in range(n):
    if mx == dist[i]:
        results.append(i)
        
mn = min(results)

print(mn + 1)
print(mx)
        