while True:
    n = int(input())  # n 입력

    if n == 0:
        break  # 입력이 0이면 종료

    # 2n 이하 소수를 판별하기 위한 에라토스테네스의 체
    # n의 최댓값은 123,456 → 2n의 최댓값은 246,912
    primenum = [True] * (2 * n + 1)

    # 0과 1은 소수가 아님
    primenum[0] = primenum[1] = False

    # 에라토스테네스의 체 수행
    # i * i <= 2n 까지만 검사해도 충분함
    i = 2
    while i * i <= 2 * n:
        if primenum[i]:  # i가 아직 소수라면
            # i의 배수들을 모두 소수가 아니라고 표시
            # j를 i*i부터 시작하는 이유: i보다 작은 배수는 이미 처리되었기 때문
            j = i * i
            while j <= 2 * n:
                primenum[j] = False
                j += i
        i += 1

    # (n, 2n] 범위에 존재하는 소수 개수 카운트
    cnt = 0
    for x in range(n + 1, 2 * n + 1):
        if primenum[x]:
            cnt += 1

    print(cnt)
