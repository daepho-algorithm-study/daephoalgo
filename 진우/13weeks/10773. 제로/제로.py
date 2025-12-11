import sys
input = sys.stdin.readline

N = int(input())  # 입력 개수

stack = []  # 값을 저장할 스택 역할의 리스트
for _ in range(N):
    x = int(input())  # 값 입력

    if x != 0:
        stack.append(x)  # 0이 아닌 경우 스택에 추가 (push)
    else:
        stack.pop()      # 0이면 최근 값을 제거 (pop)

# 스택에 남은 모든 값의 합 출력
if stack:
    print(sum(stack))  # 값이 남아 있으면 합 출력
else:
    print(0)           # 스택이 비어 있으면 0 출력
