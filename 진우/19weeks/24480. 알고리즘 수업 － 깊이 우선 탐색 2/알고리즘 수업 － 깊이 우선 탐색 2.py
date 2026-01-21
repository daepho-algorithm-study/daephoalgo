import sys
input = sys.stdin.readline

# 스택 기반 DFS 함수
def dfs(r):
    global cnt

    # DFS에 사용할 스택 (시작 정점부터 넣고 시작)
    stack = [r]

    # 스택이 빌 때까지 반복
    while stack:
        node = stack.pop()   # 스택에서 하나 꺼냄 (DFS 특성)

        # 이미 방문한 정점이면 무시
        if visited[node]:
            continue

        # 방문 처리
        visited[node] = True
        cnt += 1
        result[node] = cnt   # 방문 순서 기록

        # 인접한 정점들을 스택에 추가
        for i in range(len(arr[node])):
            nxt = arr[node][i]

            # 아직 방문하지 않은 정점만 스택에 추가
            if not visited[nxt]:
                stack.append(nxt)


# 그래프 인접 리스트 생성 (정점 번호: 1 ~ N)
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

# 각 정점의 인접 리스트를 오름차순 정렬
for i in range(1, N + 1):
    arr[i].sort()

# 시작 정점 R에서 DFS 실행
dfs(R)

# 각 정점의 방문 순서 출력
for i in range(1, N + 1):
    print(result[i])
