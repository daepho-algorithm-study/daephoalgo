import sys
import heapq

input = sys.stdin.readline

# 연산의 개수 입력
N = int(input())

# 파이썬 heapq는 기본적으로 최소 힙
# → 최대 힙처럼 사용하기 위해 값을 음수로 저장
heap = []

for _ in range(N):
    x = int(input())  # 정수 입력

    if x == 0:
        # 힙이 비어있으면 0 출력
        if not heap:
            print(0)
        else:
            # 가장 작은 값(= 음수 중 가장 작은 값)을 꺼냄
            # 다시 -를 붙여서 원래 값으로 복구
            print(-heapq.heappop(heap))
    else:
        # 최대 힙처럼 쓰기 위해 음수로 저장
        heapq.heappush(heap, -x)