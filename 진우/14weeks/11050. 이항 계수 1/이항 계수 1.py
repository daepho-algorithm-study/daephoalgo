# N, K 입력
N, K = map(int, input().split())

# N! 계산
n = 1
for i in range(N, 0, -1):
    n *= i

# K! 계산
k = 1
for i in range(K, 0, -1):
    k *= i

# (N-K)! 계산
r = 1
for i in range(N - K, 0, -1):
    r *= i

# 이항계수 nCk = N! / (K! * (N-K)!)
result = n // (k * r)

# 결과 출력
print(result)
