import sys
input = sys.stdin.readline

# DFS 함수: (r, c)에서 시작해서 연결된 집들을 모두 탐색
def dfs(r, c):
    global cnt  # 현재 단지의 집 개수

    # 상, 하, 좌, 우 이동 방향
    nx = [-1, 0, 1, 0]
    ny = [0, -1, 0, 1]

    # 네 방향으로 이동하면서 탐색
    for i in range(4):
        nr = r + nx[i]
        nc = c + ny[i]

        # 지도 범위를 벗어나면 무시
        if nr < 0 or nr >= N or nc < 0 or nc >= N:
            continue

        # 아직 방문하지 않았고, 집(1)이면
        if not visited[nr][nc] and arr[nr][nc] == 1:
            visited[nr][nc] = True   # 방문 처리
            cnt += 1                # 집 개수 증가
            dfs(nr, nc)             # 재귀 탐색

# 지도 크기 입력
N = int(input())

# 지도 입력 (문자열 형태의 0/1을 정수로 변환)
arr = [list(map(int, input().strip())) for _ in range(N)]

# 방문 여부 체크용 2차원 배열
visited = [[False] * N for _ in range(N)]

# 각 단지의 집 개수를 저장할 리스트
house = []

# 전체 지도 탐색
for i in range(N):
    for j in range(N):
        # 집이 있고 아직 방문하지 않았다면 새로운 단지 시작
        if not visited[i][j] and arr[i][j] == 1:
            cnt = 1                 # 시작 집 포함해서 1부터 카운트
            visited[i][j] = True   # 시작 위치 방문 처리
            dfs(i, j)              # DFS로 단지 전체 탐색
            house.append(cnt)      # 단지 크기 저장

# 단지 크기를 오름차순으로 정렬
house.sort()

# 단지 개수 출력
print(len(house))

# 각 단지의 집 개수 출력
for x in house:
    print(x)
