# 행렬 A : N행 M열
# 행렬 B : M행 K열
# 결과 행렬 : N행 K열

# 행렬 A의 크기 입력 (N x M)
N, M = map(int, input().split())

# 행렬 A 입력
A = []
for i in range(N):                 # A의 행
    A.append(list(map(int, input().split())))

# 행렬 B의 크기 입력 (M x K)
# A의 열(M)과 B의 행(M)은 같아야 행렬 곱 가능
M, K = map(int, input().split())

# 행렬 B 입력
B = []
for i in range(M):                 # B의 행
    B.append(list(map(int, input().split())))

# 결과 행렬 초기화 (모든 값을 0으로)
result = [[0] * K for _ in range(N)]

# 행렬 곱셈 수행
# result[n][k] = A의 n번째 행과 B의 k번째 열의 내적
for n in range(N):                 # 결과 행렬의 행 인덱스
    for k in range(K):             # 결과 행렬의 열 인덱스
        for m in range(M):         # 내적 계산용 인덱스
            # A[n][m]과 B[m][k]를 곱해 누적
            result[n][k] += A[n][m] * B[m][k]

# 결과 출력
for n in range(N):
    for k in range(K):
        print(result[n][k], end=" ")
    print()