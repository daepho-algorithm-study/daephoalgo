# N: 사용할 숫자의 범위 (1 ~ N)
# M: 만들 수열의 길이
N, M = map(int, input().split())

# 현재 만들고 있는 수열
arr = []

def sequence(n):
    # [기저 조건]
    # 길이가 M인 수열이 완성되면 출력
    if n == M:
        print(*arr)
        return

    # 1부터 N까지 숫자를 하나씩 선택
    for i in range(1, N + 1):
        arr.append(i)
        sequence(n + 1)
        arr.pop()

sequence(0)
