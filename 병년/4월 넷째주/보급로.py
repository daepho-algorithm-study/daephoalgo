from collections import deque
# from heapq import heappop, heappush

T = int(input())
for tc in range(T):
        N = int(input())
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        arr = [list(map(int, input().strip())) for _ in range(N)]
        INF = float('INF')
        dist = [[INF] * N for _ in range(N)]
        dist[0][0] = 0
        q = deque([[0, 0, 0]])
        while q:
            cost, x, y =  q.popleft()
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < N and 0 <= ny < N:
                    weight = arr[nx][ny]
                    if dist[nx][ny] > weight+ cost:
                        dist[nx][ny] = weight + cost
                        
                        if weight == 0:
                            q.appendleft([weight + cost, nx, ny])
                        else:
                            q.append([weight + cost, nx, ny])
        # q = [[0, 0, 0]]
        # while q:
        #     cost, x, y = heappop(q)
            
        #     for k in range(4):
        #         nx, ny = x + dx[k], y + dy[k]
        #         if 0 <= nx < N and 0 <= ny < N:
        #             if dist[nx][ny] > arr[nx][ny] + cost:
        #                 dist[nx][ny] = arr[nx][ny] + cost
        #                 heappush(q, [arr[nx][ny] + cost, nx, ny])
        
        print(f'#{tc + 1} {dist[N - 1][N - 1]}')          
                        
            
                