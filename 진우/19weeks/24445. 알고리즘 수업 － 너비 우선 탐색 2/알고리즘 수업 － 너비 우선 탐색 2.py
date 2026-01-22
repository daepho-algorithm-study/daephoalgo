import sys
from collections import deque   # deque 사용
input = sys.stdin.readline

# BFS 함수
def bfs(r):
    global cnt

    # 큐 생성 및 시작 정점 삽입
    q = deque([r])
    visited[r] = True

    # 큐가 빌 때까지 반복
    while q:
        node = q.popleft()   # 큐의 앞에서 꺼냄 (BFS 핵심)

        # 방문 순서 기록
        cnt += 1
        result[node] = cnt
        
        # 현재 정점의 인접 정점 탐색
        for i in range(len(arr[node])):
            nxt = arr[node][i]

            # 아직 방문하지 않은 정점이면 큐에 추가
            if not visited[nxt]:
                visited[nxt] = True   # 큐에 넣는 순간 방문 처리
                q.append(nxt)


# 그래프 인접 리스트 생성
arr = [[] for _ in range(100001)]

# 방문 여부 체크 배열
visited = [False] * 100001

# 방문 순서 저장 배열
result = [0] * 100001

# 방문 순서 카운터
cnt = 0

# 입력
N, M, R = map(int, input().split())

# 간선 입력 (무방향 그래프)
for _ in range(M):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

# 내림차순 방문을 위해 인접 리스트 정렬
for i in range(1, N + 1):
    arr[i].sort(reverse=True)

# BFS 실행
bfs(R)

# 결과 출력
for i in range(1, N + 1):
    print(result[i])
