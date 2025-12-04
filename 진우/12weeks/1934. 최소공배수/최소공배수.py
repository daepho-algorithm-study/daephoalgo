# 유클리드 호제법
# 두 정수 a, b의 최대공약수를 반환한다.
def gcd(a, b):
    while b != 0:            # b가 0이 될 때까지 반복
        a, b = b, a % b      # a ← b, b ← a % b (유클리드 호제법 핵심)
    return a                 # b가 0이 되면 a가 최대공약수

T = int(input())             # 테스트 케이스 개수 입력

for _ in range(T):
    A, B = map(int, input().split())   # 두 자연수 A, B 입력

    if A <= B:
        g = gcd(A, B)                  # 두 수의 최대공약수 계산
        result = (A * B) // g          # 최소공배수 계산: LCM = A * B / GCD
        print(result)
    else:
        g = gcd(A, B)
        result = (A * B) // g
        print(result)
