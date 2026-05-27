import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

from collections import deque

for _ in range(10):
    tc = int(input())
    arr = [list(map(int, input())) for _ in range(100)]
    x, y = 0, 0
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    flag = False
    visited = [[False for _ in range(100)] for _ in range(100)]
    for i in range(100) :
        for j in range(100):
            if arr[i][j] == 2:
                x = i 
                y = j
    q = deque([[x, y]])
    visited[x][y] = True
    while q:
        x, y = q.popleft()
        if arr[x][y] == 3:
            flag = True
            break
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            if 0 <= nx < 100 and 0 <= ny < 100 and not visited[nx][ny]:
                if arr[nx][ny] != 1:
                    visited[nx][ny] = True
                    q.append([nx, ny])
    
    if flag:
        print(f'#{tc} 1')
    else:
        print(f'#{tc} 0')