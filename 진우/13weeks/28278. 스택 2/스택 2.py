import sys
input = sys.stdin.readline

N = int(input())  # 총 명령 개수 입력

stack = []  # 스택 역할을 할 리스트 생성

for _ in range(N):
    cmd = input().split()  # 명령 입력 → 공백 단위로 분리하여 리스트로 저장

    if cmd[0] == '1':  # 명령 1 → 정수 X를 스택에 추가
        stack.append(cmd[1])

    elif cmd[0] == '2':  # 명령 2 → 스택의 top 출력 후 제거 (pop)
        if stack:               # 스택이 비어 있지 않다면
            print(stack.pop())  # pop 후 출력
        else:                   # 스택이 비어 있다면
            print(-1)

    elif cmd[0] == '3':  # 명령 3 → 스택의 크기 출력
        print(len(stack))

    elif cmd[0] == '4':  # 명령 4 → 스택이 비어 있으면 1, 아니면 0
        if stack:        # 스택이 비어 있지 않다면
            print(0)
        else:            # 스택이 비어 있다면
            print(1)

    elif cmd[0] == '5':  # 명령 5 → 스택의 top 값 출력 (제거 X)
        if stack:                # 스택이 비어 있지 않다면
            print(stack[-1])     # 리스트의 마지막 요소 출력
        else:                    # 스택이 비어 있다면
            print(-1)
