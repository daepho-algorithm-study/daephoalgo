import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

from collections import deque

T = int(input())
for tc in range(T):
    N, M = map(int, input().split())
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    arr = [list(input().strip()) for _ in range(N)]
    visited = [[False] * M for _ in range(N)]
    flag = True
    def bfs () :
        while q:
            x, y = q.popleft()
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < N and 0 <= ny < M :
                    if arr[x][y] == arr[nx][ny]:
                        return False
                    if not visited[nx][ny] :
                        if arr[nx][ny] == '?':
                            if arr[x][y] == '.':
                                arr[nx][ny] = '#'
        
                            else :
                                arr[nx][ny] = '.'
                        visited[nx][ny] = True
                        q.append((nx, ny))
        return True
    q = deque([])
    for i in range(N):
        for j in range(M):
            if not visited[i][j]:
                if  arr[i][j] != '?' :
                    q.append((i, j))
                    visited[i][j] = True
                if not bfs():
                    flag = False
                    break
        if not flag:
            break
                
    
    if flag:
        print(f'#{tc + 1} possible')
    else:
        print(f'#{tc + 1} impossible')
                    