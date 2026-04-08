from collections import deque
import sys
input = sys.stdin.readline

# BFS를 이용한 이분 그래프 판별 함수
def bfs(V, arr):
    # color 리스트: 각 노드 색상 저장
    # 0: 미방문, 1: 빨강, -1: 파랑
    color = [0] * (V + 1)

    # 모든 노드를 순회 (그래프가 연결되어 있지 않을 수 있음)
    for i in range(1, V + 1):
        if color[i] != 0:
            continue  # 이미 방문한 노드는 건너뜀

        q = deque()
        q.append(i)       # 시작 노드 큐에 삽입
        color[i] = 1      # 시작 노드를 빨강(1)으로 색칠

        # BFS 탐색
        while q:
            cur = q.popleft()

            # 현재 노드와 연결된 모든 인접 노드 확인
            for nxt in arr[cur]:
                if color[nxt] == 0:
                    # 방문하지 않은 노드는 현재 노드와 반대 색으로 칠함
                    color[nxt] = -color[cur]
                    q.append(nxt)  # 큐에 삽입하여 탐색 계속
                    
                elif color[nxt] == color[cur]:
                    # 인접 노드가 현재 노드와 같은 색이면
                    # 이분 그래프 조건 위배 → False 반환
                    return False
    # 모든 노드 탐색 후 이상 없으면 이분 그래프
    return True


K = int(input())  # 테스트케이스 수

for _ in range(K):
    V, E = map(int, input().split())  # 정점, 간선 수

    # 그래프 인접리스트 초기화
    arr = [[] for _ in range(V + 1)]

    # 간선 정보 입력
    for _ in range(E):
        u, v = map(int, input().split())
        arr[u].append(v)  # 양방향 그래프
        arr[v].append(u)

    # BFS로 이분 그래프 판별
    if bfs(V, arr):
        print("YES")  # 이분 그래프일 경우
    else:
        print("NO")   # 이분 그래프가 아닐 경우