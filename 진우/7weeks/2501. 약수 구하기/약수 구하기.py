# N과 K를 입력받음
N, K = map(int, input().split())

arr = []  # N의 약수를 저장할 리스트

# 1부터 N까지 반복하면서 약수 찾기
for i in range(1, N + 1):
    if N % i == 0:  # i가 N의 약수라면
        arr.append(i)  # 리스트에 추가

# 약수의 개수가 K개 이상이면 K번째 약수를 출력
if len(arr) >= K:
    print(arr[K - 1])
else:  # 약수의 개수가 K개 미만이면 0 출력
    print(0)
