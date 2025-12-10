import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 큐(A[i] == 0)만 deque에 저장
dq = deque()

for i in range(N):
    if A[i] == 0:
        dq.append(B[i])

M = int(input())
C = list(map(int, input().split()))

# 새 값은 앞에 넣고, 결과는 뒤에서 출력
for x in C:
    dq.appendleft(x)
    print(dq.pop(), end=" ")
