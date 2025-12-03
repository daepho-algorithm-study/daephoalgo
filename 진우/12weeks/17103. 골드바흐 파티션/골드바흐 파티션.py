# 0 ~ 1,000,000까지 소수 여부를 저장하는 리스트
# True = 소수, False = 소수 아님
primenum = [True] * 1000001
primenum[0] = primenum[1] = False  # 0과 1은 소수가 아니므로 False

# 에라토스테네스의 체로 소수 판별
i = 2
while i * i <= 1000001:  # i는 sqrt(1,000,001)까지만 반복
    if primenum[i]:       # i가 소수이면
        # i의 배수들을 소수가 아니라고 표시 (i*i부터 시작)
        for j in range(i * i, 1000001, i):
            primenum[j] = False
    i += 1

# 테스트 케이스 개수 입력
T = int(input())

for i in range(T):
    n = int(input())  # 각 테스트 케이스의 숫자 n 입력
    cnt = 0           # n을 두 소수의 합으로 만드는 경우의 수

    # num = 2 ~ n//2 까지만 확인
    # 이유: (num, n-num) 쌍은 (n-num, num)과 중복되므로 반만 확인
    for num in range(2, n // 2 + 1):
        # num과 n-num 모두 소수인지 확인
        if primenum[num] and primenum[n - num]:
            cnt += 1  # 조건 만족 시 경우의 수 1 증가

    print(cnt)  # 결과 출력 (n을 두 소수의 합으로 만드는 방법 수)
