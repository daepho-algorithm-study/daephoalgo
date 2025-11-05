# M과 N 입력 (범위의 시작과 끝)
M = int(input())
N = int(input())

# 소수를 저장할 리스트
arr = []

# M~N 사이 모든 수를 검사
for i in range(M, N + 1):
    cnt = 0  # 약수 개수를 세기 위한 변수

    # 1부터 i까지 나누어떨어지는 수의 개수 계산
    for j in range(1, i + 1):
        if (i % j) == 0:
            cnt += 1  # 나누어떨어지면 카운트 증가

    # 약수가 정확히 2개이면 소수 (1과 자기 자신만 나누어떨어짐)
    if cnt == 2:
        arr.append(i)  # 소수 리스트에 추가

# 소수가 하나라도 있는 경우
if len(arr) > 0:
    print(sum(arr))     # 소수 합 출력
    print(arr[0])       # 최소 소수 출력
else:
    print(-1)           # 소수가 없는 경우 -1 출력
