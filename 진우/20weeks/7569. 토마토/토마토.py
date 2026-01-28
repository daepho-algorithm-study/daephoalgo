import sys
from collections import deque

input = sys.stdin.readline

# 같은 층에서의 4방향 이동 (좌, 하, 우, 상)
nx = [0, 1, 0, -1]
ny = [-1, 0, 1, 0]

# 위층(-1), 아래층(+1) 이동
nz = [-1, 1]

def bfs():
    """3차원 토마토 BFS 전파 함수"""
    # 큐가 빌 때까지 반복
    while q:
        # 현재 좌표 꺼내기
        # arr = [h, x, y]
        arr = q.popleft()
        h = arr[0]
        x = arr[1]
        y = arr[2]

        # 같은 층에서 상하좌우 4방향 탐색
        for i in range(4):
            nr = x + nx[i]
            nc = y + ny[i]

            # 행, 열 범위 체크
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                continue

            # 아직 익지 않은 토마토만 전파
            if box[h][nr][nc] == 0:
                # 현재 날짜 + 1로 익음 처리
                box[h][nr][nc] = box[h][x][y] + 1
                # 다음 탐색을 위해 큐에 추가
                q.append([h, nr, nc])

        # 위층 / 아래층 탐색
        for i in range(2):
            nh = h + nz[i]

            # 높이 범위 체크
            if nh < 0 or nh >= H:
                continue

            # 같은 위치에서 위/아래 층 토마토 확인
            if box[nh][x][y] == 0:
                box[nh][x][y] = box[h][x][y] + 1
                q.append([nh, x, y])


# 3차원 토마토 상자
# box[h][x][y]
box = []

# BFS를 위한 큐
q = deque()

# 가장 늦게 익은 날짜 저장
mx = -9999999

# 입력: M(가로), N(세로), H(높이)
M, N, H = map(int, input().split())

# 토마토 정보 입력
for i in range(H):
    # 한 층(N x M) 입력
    arr = [list(map(int, input().split())) for _ in range(N)]
    box.append(arr)

# 이미 익은 토마토를 BFS 시작점으로 큐에 넣기 (다중 시작점)
for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 1:
                q.append([i, j, k])

# BFS 실행
bfs()

# 결과 확인
for i in range(H):
    for j in range(N):
        for k in range(M):
            # 안 익은 토마토가 남아있으면 실패
            if box[i][j][k] == 0:
                print(-1)
                sys.exit()

            # 가장 늦게 익은 날짜 갱신
            if box[i][j][k] > mx:
                mx = box[i][j][k]

# 시작 날짜가 1이므로 -1
print(mx - 1)
