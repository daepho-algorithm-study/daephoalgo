import sys
input = sys.stdin.readline

N = int(input())  # 창문의 개수 N 입력

cnt = 0

# 1^2, 2^2, 3^2 ... i^2 형태로
# 완전제곱수만 마지막에 창문이 열리게 됨
# 따라서 i^2 <= N 을 만족하는 i의 개수를 카운트
i = 1
while i * i <= N:
    cnt += 1
    i += 1

# 마지막에 열려 있는 창문의 개수 출력
print(cnt)
