import heapq

n, m, x = map(int, input().split(" "))
graph = [[] for _ in range(n)]

reversed_graph = [[] for _ in range(n)]

for _ in range(m) :
    a, b, c = map(int, input().split(" "))
    graph[a - 1].append([b - 1,  c])
    reversed_graph[b - 1].append([a - 1, c])

def dijkstra(start, graph):
    dist = [float("inf") for _ in range(n)]
    q = []
    heapq.heappush(q, [0, start])
    dist[start] = 0
    while q:
        cur, now = heapq.heappop(q)

        if dist[now] < cur:
            continue

        for [next, cost] in graph[now] :
            nextDist = cur + cost
            if nextDist < dist[next] :
                dist[next] = nextDist
                heapq.heappush(q, [nextDist, next])
    return dist

result = []
x_from = dijkstra(x - 1, graph)
x_to = dijkstra(x - 1, reversed_graph)

result = 0
for i in range(n) :
    result = max(result, x_from[i] + x_to[i])

print(result)