import sys
input = sys.stdin.readline   # 빠른 입력 처리

# N: 배열 길이, K: 연속 구간 길이
N, K = map(int, input().split())

# 배열 입력
arr = list(map(int, input().split()))

# 첫 구간 [0 ~ K-1] 합 계산
result = sum(arr[:K])

# 현재까지 최대 합으로 초기화
mx = result

# 슬라이딩 윈도우: 윈도우를 한 칸씩 오른쪽으로 이동
for i in range(K, N):
    # 이전 구간 합에서
    # - arr[i-K] : 빠지는 값
    # + arr[i]   : 새로 들어오는 값
    result = result - arr[i - K] + arr[i]

    # 최대값 갱신
    mx = max(mx, result)

# 연속된 K개의 합 중 최대값 출력
print(mx)
