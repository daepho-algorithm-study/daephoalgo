N = int(input())

stack = []

for _ in range(N):
    arr = list(map(str, input()))
    stack = []

    result = 'YES'  # 괄호의 짝이 맞다면 YES

    for i in range(len(arr)):  # arr의 길이 만큼 반복
        if arr[i] == '(':  # (라면
            stack.append(arr[i])  # stack에 추가

        elif arr[i] == ')':  # )인데
            if not stack:  # stack이 0이라면 
                result = 'NO'  # NO
                break
            stack.pop()  # 스택의 마지막 값을 삭제

    if len(stack) >= 1:  # 삭제가 끝났음에도 스택에 값이 있다면
        result = 'NO'  # NO

    print(result)
