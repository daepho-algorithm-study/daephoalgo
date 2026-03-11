from collections import deque

N, start, end, M = map(int, input().split());
edge = []
for _ in range(M):
    a, b, c = map(int, input().split());
    edge.append([a,b,c])
money = list(map(int, input().split()))
INF = float('inf')
dist = [INF for _ in range(N)]
queue = deque()
visitied = [False for _ in range(N)]

def bellman_ford(start):
    dist[start] = -money[start]

    for _ in range(N - 1):
        for s, e, cost in edge:
            if dist[s] != INF and dist[e] > dist[s] + cost - money[e] :
                dist[e] = dist[s] + cost - money[e]
    
    for s, e, cost in edge:
        if dist[s] != INF and dist[e] > dist[s] + cost - money[e]:
            queue.append(e)
            visitied[e] = True

def bfs():
    while queue:
        now = queue.popleft()
        if now == end:
            return True
        for s,e,_ in edge:
            if s == now:
                if not visitied[e]:
                    visitied[e] = True
                    queue.append(e)
    return False

bellman_ford(start)
flag = bfs()
if dist[end] == INF:
    print('gg')
else :
    if flag :
        print("Gee")
    else :
        print(-dist[end])
