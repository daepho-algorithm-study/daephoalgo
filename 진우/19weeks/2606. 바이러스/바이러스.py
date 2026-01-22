import sys
input = sys.stdin.readline

# 깊이 우선 탐색(DFS) 함수
def dfs(n):
    global cnt  # 감염된 컴퓨터 수를 전역 변수로 사용

    # 현재 컴퓨터를 방문 처리
    visited[n] = True

    # 현재 컴퓨터와 연결된 모든 컴퓨터 탐색
    for i in range(len(arr[n])):
        nxt = arr[n][i]

        # 아직 방문하지 않은 컴퓨터라면
        if not visited[nxt]:
            cnt += 1      # 새로 감염되는 컴퓨터 수 증가
            dfs(nxt)     # 다음 컴퓨터로 DFS 진행

# 인접 리스트 (각 컴퓨터에 연결된 컴퓨터 목록)
arr = [[] for _ in range(101)]

# 방문 여부 체크 배열
visited = [False] * 101

# 1번 컴퓨터로부터 감염되는 컴퓨터 수
cnt = 0

# 컴퓨터 수
N = int(input())

# 연결된 쌍의 개수
M = int(input())

# 네트워크 연결 정보 입력 (양방향)
for _ in range(M):
    u, v = map(int, input().split())

    arr[u].append(v)
    arr[v].append(u)

# 1번 컴퓨터부터 DFS 시작
dfs(1)

# 감염된 컴퓨터 수 출력 (1번 제외)
print(cnt)
