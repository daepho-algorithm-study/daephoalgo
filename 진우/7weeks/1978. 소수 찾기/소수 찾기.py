# 입력받은 수의 개수 N을 저장
N = int(input())

# N개의 정수를 입력받아 리스트로 저장
# 예: "1 3 5 7" → [1, 3, 5, 7]
arr = list(map(int, input().split()))

result = 0  # 소수의 개수를 저장할 변수

# arr 리스트에 있는 각 수에 대해 반복
for i in range(N):
    cnt = 0  # 약수의 개수를 셀 변수

    # 1부터 arr[i]까지 나누어 약수 개수 확인
    for j in range(1, arr[i] + 1):
        if (arr[i] % j) == 0:  # j가 arr[i]의 약수라면
            cnt += 1

    # 약수가 2개(1과 자기 자신)인 경우 소수이므로 카운트
    if cnt == 2:
        result += 1

# 소수의 총 개수 출력
print(result)
