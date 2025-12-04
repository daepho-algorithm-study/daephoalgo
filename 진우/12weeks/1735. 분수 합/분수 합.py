import sys
input = sys.stdin.readline   # 빠른 입력

# 최대공약수(GCD)를 구하는 함수 — 유클리드 호제법
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# 분수 a/b 를 기약분수로 변환하여 (분자, 분모) 형태로 반환
def simplify(a, b):
    g = gcd(a, b)      # 최대공약수
    return a // g, b // g   # gcd로 나누어 기약분수 형태로 반환

# 2×2 행렬 입력
# arr = [[a, b], [c, d]]
arr = [list(map(int, input().split())) for _ in range(2)]

# 두 분수 (a/b + c/d) 를 계산
# 분자 = ad + bc
A = arr[0][0] * arr[1][1] + arr[1][0] * arr[0][1]

# 분모 = bd
B = arr[0][1] * arr[1][1]

# 기약분수 변환
numerator, denominator = simplify(A, B)

# 결과 출력
print(numerator, denominator)
