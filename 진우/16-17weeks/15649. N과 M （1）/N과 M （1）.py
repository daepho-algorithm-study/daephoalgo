# N: 사용할 숫자의 범위 (1 ~ N)
# M: 만들 수열의 길이
N, M = map(int, input().split())

# 현재 만들고 있는 수열
arr = []

# 숫자 사용 여부 체크 (1 ~ 8까지 가능)
visited = [False] * 9


# 백트래킹 함수
# n : 현재까지 선택한 숫자의 개수
def sequence(n):
    # [기저 조건]
    # 길이가 M인 수열이 완성되면 출력
    if n == M:
        print(*arr)
        return

    # 1부터 N까지 숫자를 하나씩 선택
    for i in range(1, N + 1):

        # 이미 사용한 숫자라면 건너뜀
        if visited[i]:
            continue

        # 선택
        arr.append(i)
        visited[i] = True

        # 다음 자리 채우기
        sequence(n + 1)

        # 되돌리기 (백트래킹)
        visited[i] = False
        arr.pop()

sequence(0)
