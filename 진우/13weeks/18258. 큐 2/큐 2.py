import sys
input = sys.stdin.readline   # 빠른 입력
from collections import deque

N = int(input())  # 명령어 개수 입력

q = deque()       # 정수를 저장할 큐 (FIFO)

for _ in range(N):
    cmd = input().split()  # 명령 입력 (push X 형태 대비 split 사용)

    # push X : 정수 X를 큐에 삽입
    if cmd[0] == "push":
        q.append(int(cmd[1]))

    # pop : 큐의 첫 원소 출력 후 제거
    elif cmd[0] == "pop":
        if q:
            print(q.popleft())
        else:
            print(-1)

    # size : 큐 크기 출력
    elif cmd[0] == "size":
        print(len(q))

    # empty : 큐가 비었으면 1, 아니면 0 출력
    elif cmd[0] == "empty":
        if q:
            print(0)
        else:
            print(1)
            
    # front : 큐의 첫 원소 출력 (제거 X)
    elif cmd[0] == "front":
        if q:
            print(q[0])
        else:
            print(-1)

    # back : 큐의 마지막 원소 출력 (제거 X)
    elif cmd[0] == "back":
        if q:
            print(q[-1])
        else:
            print(-1)
