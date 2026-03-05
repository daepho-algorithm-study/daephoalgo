import heapq  # 파이썬 힙 기능 제공
import sys

input = sys.stdin.readline  

# 입력
N = int(input())  # 연산 개수

# ---------------------------
# 힙 선언
# 파이썬 힙은 최소 힙이 기본
# (절댓값, 실제 값) 형태로 저장하면
# 1️⃣ 절댓값이 작은 순서
# 2️⃣ 절댓값 같으면 실제 값이 작은 순서
# 자동으로 처리됨
# ---------------------------
heap = []

for _ in range(N):
    x = int(input())

    if x == 0:
        # 큐가 비어있다면 0 출력
        if not heap:
            print(0)
        else:
            # heappop()으로 가장 우선순위 높은 원소 꺼내기
            # 꺼낸 값의 실제 값은 [1]에 저장되어 있음
            print(heapq.heappop(heap)[1])
    else:
        # 0이 아닌 값은 (절댓값, 실제값) 형태로 삽입
        heapq.heappush(heap, (abs(x), x))