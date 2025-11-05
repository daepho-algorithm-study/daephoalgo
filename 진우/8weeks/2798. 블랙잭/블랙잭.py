# 카드의 개수 N, 목표 값 M 입력
N, M = map(int, input().split())

# 카드 숫자 리스트 입력
arr = list(map(int, input().split()))

result = 0  # M을 넘지 않는 최대 합 저장

# 세 장의 카드를 고르는 모든 조합 탐색
for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            num = arr[i] + arr[j] + arr[k]  # 세 카드의 합
            if num <= M and num > result:
                result = num  # M 이하인 최대합 갱신

print(result)
