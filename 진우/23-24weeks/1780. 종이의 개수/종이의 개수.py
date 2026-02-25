import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

# 결과 카운트
zero = 0    # 값이 0인 종이 개수
one = 0     # 값이 1인 종이 개수
other = 0   # 값이 -1인 종이 개수


"""
(x, y)를 좌상단으로 하는 l × l 영역을 검사하는 함수

- 영역이 모두 같은 값이면 해당 값 카운트 증가
- 다른 값이 섞여 있으면 영역을 3 × 3 (총 9개)로 분할하여 재귀 호출
"""
def check(x, y, l):
    global zero, one, other

    # 현재 영역의 기준 값 (좌상단)
    first_color = board[x][y]

    # 현재 l × l 영역이 모두 같은 값인지 확인
    for i in range(x, x + l):
        for j in range(y, y + l):
            # 기준 값과 다른 값이 하나라도 발견되면 분할
            if board[i][j] != first_color:
                k = l // 3  # 영역을 3등분할 크기

                # 3 × 3 형태로 총 9개의 영역을 재귀적으로 검사
                check(x, y, k)
                check(x, y + k, k)
                check(x, y + 2 * k, k)

                check(x + k, y, k)
                check(x + k, y + k, k)
                check(x + k, y + 2 * k, k)

                check(x + 2 * k, y, k)
                check(x + 2 * k, y + k, k)
                check(x + 2 * k, y + 2 * k, k)

                return  # 분할했으므로 현재 영역은 카운트하지 않음

    # 여기까지 왔다는 것은 영역이 모두 같은 값이라는 뜻
    if first_color == 1:
        one += 1
    elif first_color == 0:
        zero += 1
    else:
        other += 1


# 종이 한 변의 길이 (3의 제곱수)
N = int(input())

# 종이 정보 입력
board = [list(map(int, input().split())) for _ in range(N)]

# 전체 영역부터 분할 정복 시작
check(0, 0, N)

# 문제에서 요구한 순서대로 출력
print(other)  # -1 개수
print(zero)   # 0 개수
print(one)    # 1 개수