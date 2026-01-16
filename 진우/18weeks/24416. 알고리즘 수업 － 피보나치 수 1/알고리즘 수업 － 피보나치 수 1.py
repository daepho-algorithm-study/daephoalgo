import sys
input = sys.stdin.readline

# 재귀 방식에서 fib(1), fib(2)가 호출된 횟수
cnt1 = 0

# DP 방식에서 반복문이 실행된 횟수
cnt2 = 0

# -------------------------------
# 재귀 방식 피보나치
# -------------------------------
def fib(n):
    global cnt1

    # fib(1) 또는 fib(2)가 호출될 때 카운트
    if n == 1 or n == 2:
        cnt1 += 1
        return 1

    # 재귀 호출
    return fib(n - 1) + fib(n - 2)

# -------------------------------
# DP 방식 피보나치
# -------------------------------
def fibonacci(n):
    global cnt2

    # 피보나치 수를 저장할 리스트
    arr = [0] * (n + 1)

    # 초기값
    arr[1] = arr[2] = 1

    # 반복문이 실행될 때마다 카운트
    for i in range(3, n + 1):
        arr[i] = arr[i - 1] + arr[i - 2]
        cnt2 += 1

    return arr[n]

N = int(input())

fib(N)
fibonacci(N)

print(cnt1, cnt2)