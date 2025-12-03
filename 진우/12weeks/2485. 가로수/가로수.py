import sys
input = sys.stdin.readline   # 빠른 입력

# 최대공약수 함수 (유클리드 호제법)
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

N = int(input())
arr = [int(input()) for _ in range(N)]  # 나무 위치 입력

# 인접한 두 나무의 간격 중 첫 값으로 gcd 초기화
g = arr[1] - arr[0]
for i in range(1, N - 1):
    g = gcd(g, arr[i + 1] - arr[i])  # 모든 구간의 공약수(등차) 계산

# 전체 거리 계산 (맨 마지막 - 맨 처음)
total_len = arr[-1] - arr[0]

# 있어야 하는 전체 나무 수: (전체 길이 / 간격) + 1
total_trees = total_len // g + 1

# 새로 심어야 하는 나무 수 = 전체 있어야 할 나무 수 - 현재 나무 수
print(total_trees - N)
