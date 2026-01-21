import sys
input = sys.stdin.readline

# 인접 리스트 (정점 1 ~ N)
arr = [[] for _ in range(200001)]

# 방문 여부 체크 배열
visited = [False] * 200001

# 각 정점의 방문 순서를 저장할 배열
result = [0] * 200001

# 방문 순서 카운터
cnt = 0

# 스택 기반 DFS 함수
def dfs(r):
    global cnt

    # 시작 정점을 스택에 넣고 시작
    stack = [r]

    # 스택이 빌 때까지 반복
    while stack:
        node = stack.pop()   # 스택에서 하나 꺼냄 (LIFO)

        # 이미 방문한 정점이면 스킵
        if visited[node]:
            continue

        # 현재 정점 방문 처리
        visited[node] = True

        # 방문 순서 기록
        cnt += 1
        result[node] = cnt

        # 오름차순 방문을 위해 역순으로 push
        for i in range(len(arr[node]) - 1, -1, -1):
            nxt = arr[node][i]

            if not visited[nxt]:
                stack.append(nxt)


# 입력: 정점 개수 N, 간선 개수 M, 시작 정점 R
N, M, R = map(int, input().split())

# 간선 입력 (무방향 그래프)
for _ in range(M):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)

# 각 정점의 인접 리스트 오름차순 정렬
for i in range(1, N + 1):
    arr[i].sort()

# DFS 실행
dfs(R)

# 방문 순서 출력
for i in range(1, N + 1):
    print(result[i])
