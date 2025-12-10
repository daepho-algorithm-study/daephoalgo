N = int(input())  # 총 사람 수 입력

line = list(map(int, input().split()))  # 대기줄에 서 있는 사람들의 번호

stack = []         # 옆으로 빠지는 대기 공간(스택)
current = 1        # 지금 나와야 하는 번호 (1부터 시작)

for i in range(N):
    # 줄 맨 앞의 사람이 현재 나와야 하는 번호라면 바로 보냄
    if line[i] == current:
        current += 1
    else:
        # 아니라면 스택에 대기
        stack.append(line[i])

    # 스택의 맨 위에 있는 사람이 현재 나와야 하는 번호라면 계속 꺼냄
    while stack and current == stack[-1]:
        stack.pop()
        current += 1

# 스택이 비어있으면 모든 사람이 순서대로 나갔다는 뜻
if stack:
    print("Sad")
else:
    print("Nice")
