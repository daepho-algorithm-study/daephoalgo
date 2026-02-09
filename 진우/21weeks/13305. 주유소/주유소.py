import sys
input = sys.stdin.readline

N = int(input())

# 도시 사이 거리 (N-1개)
dist = list(map(int, input().split()))

# 각 도시의 기름 가격 (N개)
cost = list(map(int, input().split()))

mn = cost[0]   # 지금까지의 최소 기름값
total = 0      # 총 비용

# 마지막 도시는 이동이 없으므로 N-1까지만
for i in range(N - 1):
    if cost[i] < mn:
        mn = cost[i]
    total += mn * dist[i]

print(total)
