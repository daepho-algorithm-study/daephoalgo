# w(a, b, c)의 결과를 저장해 두는 메모이제이션 배열
# a, b, c는 최대 20까지만 의미 있으므로 크기를 21로 잡음
arr = [[[0] * 21 for _ in range(21)] for _ in range(21)]

# 재귀 함수 w(a, b, c)
def w(a, b, c):

    # 종료 조건 1:
    # a, b, c 중 하나라도 0 이하이면 항상 1 반환
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    # 종료 조건 2:
    # a, b, c 중 하나라도 20 초과면 w(20, 20, 20)과 동일
    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)

    # 이미 계산한 값이 있으면 재귀 호출 없이 바로 반환
    if arr[a][b][c] != 0:
        return arr[a][b][c]

    # 조건: a < b < c 인 경우
    # 문제에서 주어진 공식 그대로 사용
    if a < b and b < c:
        arr[a][b][c] = (
            w(a, b, c - 1)
            + w(a, b - 1, c - 1)
            - w(a, b - 1, c)
        )

    # 그 외의 모든 경우
    # 문제에서 주어진 공식 그대로 사용
    else:
        arr[a][b][c] = (
            w(a - 1, b, c)
            + w(a - 1, b - 1, c)
            + w(a - 1, b, c - 1)
            - w(a - 1, b - 1, c - 1)
        )

    # 계산한 값을 배열에 저장해 두고 반환
    return arr[a][b][c]


# 입력 처리
while True:
    a, b, c = map(int, input().split())

    # 종료 조건
    if a == -1 and b == -1 and c == -1:
        break

    # 결과 출력 형식은 문제 요구사항 그대로
    print(f"w({a}, {b}, {c}) = {w(a, b, c)}")
