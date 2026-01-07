# ---------------------------
# 하노이 탑 재귀 함수
# n   : 이동할 원판 개수
# one : 출발 기둥
# two : 보조 기둥
# three : 목적지 기둥
# ---------------------------
def move(n, one, two, three):
    # [기저 조건] 원판이 1개이면 바로 출발 → 목적지 이동
    if n == 1:
        print(one, three)  # 이동 출력
        return
    else:
        # n-1개의 원판을 보조 기둥으로 이동
        # 출발: one, 목적지: two, 보조: three
        move(n - 1, one, three, two)

        # 가장 큰 원판을 출발 → 목적지 이동
        print(one, three)

        # n-1개의 원판을 목적지로 이동
        # 출발: two, 목적지: three, 보조: one
        move(n - 1, two, one, three)

N = int(input())  # 원판 개수 입력

# 총 이동 횟수 출력: 2^N - 1
print((1 << N) - 1)  # 1 << N 은 2^N

# 하노이 탑 이동 시작
# 1번 기둥 → 3번 기둥, 2번 기둥은 보조
move(N, 1, 2, 3)
