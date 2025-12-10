import sys
from collections import deque

input = sys.stdin.readline  # 빠른 입력 적용

N = int(input())  # 카드 개수 입력

q = deque()  # 큐(덱) 생성

# 1부터 N까지 차례대로 큐에 삽입
for i in range(1, N + 1):
    q.append(i)

# 카드가 1장 남을 때까지 반복
while len(q) != 1:
    q.popleft()              # 맨 위 카드 버리기
    q.append(q.popleft())    # 다음 카드 뒤로 보내기

print(q[0])  # 마지막 카드 출력
