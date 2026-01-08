import sys
input = sys.stdin.readline

N = int(input())              # 숫자의 개수
num = list(map(int, input().split()))  # 숫자 리스트
oper = list(map(int, input().split())) # 연산자 개수 [+,-,*,/]

mx = -1000000001
mn =  1000000001


def fun(x, n):
    """
    x : 현재까지 계산된 결과값
    n : 다음에 사용할 숫자의 인덱스 (num[n])
    """

    global mx, mn

    # 모든 숫자를 다 사용한 경우
    if n == N:
        mx = max(mx, x)   # 최댓값 갱신
        mn = min(mn, x)   # 최솟값 갱신
        return

    # 4가지 연산자를 하나씩 시도
    for i in range(4):
        if oper[i] > 0:
            oper[i] -= 1   # 연산자 하나 사용

            # 덧셈
            if i == 0:
                fun(x + num[n], n + 1)

            # 뺄셈
            elif i == 1:
                fun(x - num[n], n + 1)

            # 곱셈
            elif i == 2:
                fun(x * num[n], n + 1)

            # 나눗셈
            else:
                if x < 0:
                    fun(-(-x // num[n]), n + 1)
                else:
                    fun(x // num[n], n + 1)

            oper[i] += 1   # 백트래킹: 연산자 복구


# 첫 번째 숫자를 초기값으로 사용
# n = 1 → 다음에 사용할 숫자는 num[1]
fun(num[0], 1)

# 결과 출력
print(mx)
print(mn)
