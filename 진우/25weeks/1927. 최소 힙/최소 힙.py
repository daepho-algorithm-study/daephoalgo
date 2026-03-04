import sys
import heapq

input = sys.stdin.readline

# 연산의 개수 입력
N = int(input())

# Python heapq는 기본이 최소 힙(Min Heap)
heap = []

for _ in range(N):
    x = int(input())  # 정수 입력

    if x == 0:
        # 힙이 비어있으면 0 출력
        if not heap:
            print(0)
        else:
            # 가장 작은 값 반환 (최소 힙이므로)
            print(heapq.heappop(heap))
    else:
        # 값 삽입 (자동으로 힙 구조 유지, O(log N))
        heapq.heappush(heap, x)