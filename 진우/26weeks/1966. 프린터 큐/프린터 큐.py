import sys
from collections import deque
import heapq

input = sys.stdin.readline

# 테스트 케이스 개수
T = int(input())

for _ in range(T):

    N, M = map(int, input().split())
    # N : 문서 개수
    # M : 우리가 궁금한 문서의 인덱스

    q = deque()   # (우선순위, 인덱스)
    pq = []       # 최대 우선순위 확인용 힙

    # 우선순위 입력
    arr = list(map(int, input().split()))

    for i in range(N):
        q.append((arr[i], i))      # 큐에 (우선순위, 인덱스)
        heapq.heappush(pq, -arr[i])  # 최대 힙처럼 사용

    cnt = 0

    while q:

        p, idx = q.popleft()

        # 현재 문서가 최고 우선순위가 아니면 뒤로 이동
        if p != -pq[0]:
            q.append((p, idx))

        else:
            cnt += 1
            heapq.heappop(pq)

            # 찾는 문서라면 종료
            if idx == M:
                print(cnt)
                break