import sys
input = sys.stdin.readline

N = int(input())                 # 전체 사람 수 (항상 짝수)
team = [list(map(int, input().split())) for _ in range(N)]
visited = [False] * N            # visited[i] == True → i번 사람은 start 팀
mn = 10**9                        # 최소 능력치 차이 저장


# x : 다음에 선택할 사람의 시작 인덱스
# n : 현재 start 팀에 선택된 사람 수
def dfs(x, n):
    global mn

    # start 팀 인원이 정확히 N/2명이 되면 점수 계산
    if n == N // 2:
        start = 0
        link = 0

        # 모든 사람 쌍 (i, j)에 대해
        for i in range(N):
            for j in range(N):

                # 둘 다 start 팀인 경우
                if visited[i] and visited[j]:
                    start += team[i][j]

                # 둘 다 link 팀인 경우
                if not visited[i] and not visited[j]:
                    link += team[i][j]

        # 두 팀 능력치 차이 계산
        result = abs(start - link)

        # 최소값 갱신
        mn = min(mn, result)
        return  # 이 조합 탐색 종료

    # 아직 start 팀 인원이 부족한 경우
    # x부터 N-1까지 사람 중 한 명을 start 팀으로 선택
    for i in range(x, N):
        visited[i] = True         # i번 사람을 start 팀에 넣고
        dfs(i + 1, n + 1)         # 다음 사람 탐색 (중복 방지)
        visited[i] = False        # 백트래킹 (원상 복구)


# start 팀 조합 탐색 시작
dfs(0, 0)

# 최소 능력치 차이 출력
print(mn)
