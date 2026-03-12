# 컵을 섞는 횟수 입력
m = int(input())

# 현재 공이 들어있는 컵 번호 (처음에는 1번 컵)
num = 1

# m번 동안 컵 위치를 바꾸는 작업 수행
for _ in range(m):
    # 서로 위치를 바꿀 두 컵 번호 입력
    a, b = map(int, input().split())

    # 공이 a번 컵에 있었다면 b번 컵으로 이동
    if num == a:
        num = b

    # 공이 b번 컵에 있었다면 a번 컵으로 이동
    elif num == b:
        num = a

# 모든 섞기가 끝난 후 공이 들어있는 컵 번호 출력
print(num)