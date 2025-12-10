import sys
from collections import deque

input = sys.stdin.readline

N = int(input())  # 명령어 개수
dq = deque()      # 덱 생성

for _ in range(N):
    cmd = list(map(int, input().split()))
    
    # 1 X : 앞에 삽입
    if cmd[0] == 1:
        dq.appendleft(cmd[1])

    # 2 X : 뒤에 삽입
    elif cmd[0] == 2:
        dq.append(cmd[1])

    # 3 : 앞에서 출력 후 제거
    elif cmd[0] == 3:
        if dq:
            print(dq.popleft())
        else:
            print(-1)

    # 4 : 뒤에서 출력 후 제거
    elif cmd[0] == 4:
        if dq:
            print(dq.pop())
        else:
            print(-1)

    # 5 : 크기 출력
    elif cmd[0] == 5:
        print(len(dq))

    # 6 : 비었는지 출력 (비었으면 1, 아니면 0)
    elif cmd[0] == 6:
        if dq:
            print(0)
        else:
            print(1)

    # 7 : 앞 값 출력 (제거 X)
    elif cmd[0] == 7:
        if dq: 
            print(dq[0])
        else:
            print(-1)

    # 8 : 뒤 값 출력 (제거 X)
    elif cmd[0] == 8:
        if dq: 
            print(dq[-1])
        else:
            print(-1)