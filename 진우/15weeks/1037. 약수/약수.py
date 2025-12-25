N = int(input())  # 약수(또는 수)의 개수 입력

# N개의 정수를 리스트로 입력받음
num = list(map(int, input().split()))

# 약수들을 오름차순으로 정렬
num.sort()

# 결과 계산
# 약수의 개수가 짝수인 경우
if N % 2 == 0:
    # 1과 자기 자신이 제외된 약수들이므로
    # 가장 작은 값 × 가장 큰 값 = 원래 수
    result = num[0] * num[N - 1]

# 약수의 개수가 홀수인 경우
else:
    # 완전 제곱수인 경우로
    # 가운데 약수는 √N에 해당
    result = num[N // 2] * num[N // 2]

# 결과 출력
print(result)
