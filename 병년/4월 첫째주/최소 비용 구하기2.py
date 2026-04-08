import heapq

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


start, end = map(int, input().split())
dist = [float("inf")] * (n + 1)
prev = [-1] * (n + 1)
def dijkstra(start) :
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0
    
    while q :
        cur, now = heapq.heappop(q)
        
        if dist[now] < cur :
            continue
        
        for next, cost in graph[now]:
            nextcost = cur + cost
            if nextcost < dist[next] :
                dist[next] = nextcost
                prev[next] = now
                heapq.heappush(q, (nextcost, next))

dijkstra(start)
result = []
# def dfs(start):
#     global cnt
#     cnt += 1
#     if prev[start] == -1:
#         result.append(start)
#         return
#     dfs(prev[start])
#     result.append(start)

# dfs(end)
def trace(node) :
    while node != -1:
        result.append(node)
        node = prev[node]
trace(end)
result.reverse()
print(dist[end])
print(len(result))
print(*result)