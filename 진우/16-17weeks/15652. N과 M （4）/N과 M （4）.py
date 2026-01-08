# N: 사용할 숫자의 범위 (1 ~ N)
# M: 만들 수열의 길이
N, M = map(int, input().split())

# 현재까지 선택된 숫자들을 저장하는 리스트
arr = []

def sequence(n, start):
    """
    n     : 현재까지 선택한 숫자의 개수
    start : 다음에 선택할 수 있는 최소 숫자
    """

    # [기저 조건]
    # M개의 숫자를 모두 선택했으면 수열 완성 → 출력
    if n == M:
        print(*arr)
        return

    # start부터 N까지 숫자를 하나씩 선택
    for i in range(start, N + 1):

        # 현재 숫자 i를 선택
        arr.append(i)

        # 다음 단계로 이동
        # 다음 숫자는 반드시 i와 같은 값부터 선택해야 함
        sequence(n + 1, i)

        # 백트래킹:
        # 선택했던 숫자를 제거하고 다른 경우 탐색
        arr.pop()


# 수열 생성 시작
sequence(0, 1)
