import sys
input = sys.stdin.readline

# BFS 함수
def bfs(r):
    global cnt

    # 큐 역할을 할 리스트 (시작 정점 삽입)
    q = [r]

    # 시작 정점 방문 처리
    visited[r] = True

    # 큐가 빌 때까지 반복
    while q:
        node = q.pop(0)   # 큐에서 하나 꺼냄

        # 방문 순서 기록
        cnt += 1
        result[node] = cnt

        # 현재 정점과 인접한 정점 탐색
        for i in range(len(arr[node])):
            nxt = arr[node][i]
            
            # 아직 방문하지 않은 정점이면 큐에 추가
            if not visited[nxt]:
                visited[nxt] = True   # 방문 처리
                q.append(nxt)


# 그래프 인접 리스트 생성
arr = [[] for _ in range(100001)]

# 방문 여부 체크 배열
visited = [False] * 100001

# 방문 순서를 저장할 배열
result = [0] * 100001

# 방문 순서 카운터
cnt = 0

# 입력 받기
N, M, R = map(int, input().split())

# 간선 입력 (무방향 그래프)
for _ in range(M):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

# 오름차순 방문을 위해 인접 리스트 정렬
for i in range(1, N + 1):
    arr[i].sort()

# BFS 실행
bfs(R)

# 각 정점의 방문 순서 출력
for i in range(1, N + 1):
    print(result[i])
