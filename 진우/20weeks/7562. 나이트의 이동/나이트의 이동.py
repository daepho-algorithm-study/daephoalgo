from collections import deque

# 테스트 케이스 수
T = int(input())

# 나이트의 이동 방향 (8가지)
nx = [-1, -2, -2, -1,  1,  2,  2,  1]
ny = [-2, -1,  1,  2,  2,  1, -1, -2]

def bfs(start_x, start_y, target_x, target_y, I):
    # visited[r][c]
    # -1 : 아직 방문하지 않음
    #  0 이상 : (r,c)까지의 최소 이동 횟수
    visited = [[-1] * I for _ in range(I)]

    # 시작 위치 방문 처리
    visited[start_x][start_y] = 0

    # BFS용 큐
    q = deque()
    q.append((start_x, start_y))

    while q:
        row, col = q.popleft()

        # 목표 위치에 도착하면 종료 (최단 거리)
        if row == target_x and col == target_y:
            return visited[row][col]

        # 나이트의 8가지 이동
        for i in range(8):
            nr = row + nx[i]
            nc = col + ny[i]

            # 체스판 범위 체크
            if nr < 0 or nr >= I or nc < 0 or nc >= I:
                continue

            # 아직 방문하지 않은 칸이면
            if visited[nr][nc] == -1:
                visited[nr][nc] = visited[row][col] + 1
                q.append((nr, nc))

    return visited[target_x][target_y]


# 각 테스트 케이스 처리
for _ in range(T):
    I = int(input())

    # 시작 좌표
    sx, sy = map(int, input().split())
    # 목표 좌표
    tx, ty = map(int, input().split())

    # BFS 실행 및 결과 출력
    print(bfs(sx, sy, tx, ty, I))
