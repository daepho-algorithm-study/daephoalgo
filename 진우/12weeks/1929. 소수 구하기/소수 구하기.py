# 소수 구간 [M, N] 입력
M, N = map(int, input().split())

# 에라토스테네스의 체를 위한 리스트
# 길이 1,000,001, 모든 값을 True로 초기화
primenum = [True] * 1000001

# 0과 1은 소수가 아님
primenum[0] = primenum[1] = False

# 에라토스테네스의 체 수행
# i * i <= N 까지만 검사해도 충분함
i = 2
while i * i <= N:
    if primenum[i]:      # i가 아직 소수라면
        # i의 배수를 모두 소수가 아닌 것으로 처리
        # i*i부터 시작 → i보다 작은 배수는 이미 처리됨
        for j in range(i * i, N + 1, i):
            primenum[j] = False
    i += 1

# M부터 N까지 범위의 소수 출력
for num in range(M, N + 1):
    if primenum[num]:
        print(num)
