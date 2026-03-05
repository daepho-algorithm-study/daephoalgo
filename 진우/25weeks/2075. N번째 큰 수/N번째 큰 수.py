import sys
import heapq

input = sys.stdin.readline

# N 입력
N = int(input())

# 숫자 배열 입력
arr = [list(map(int, input().split())) for _ in range(N)]

# 최소 힙 생성
heap = []


# 상위 N개 값만 유지
for row in arr:           # 각 행 접근
    for x in row:         # 행 안의 각 원소 접근

        heapq.heappush(heap, x)

        # 힙 크기가 N을 초과하면
        # 가장 작은 값 제거
        if len(heap) > N:
            heapq.heappop(heap)

# 힙의 최솟값 = 전체에서 N번째로 큰 값
print(heap[0])