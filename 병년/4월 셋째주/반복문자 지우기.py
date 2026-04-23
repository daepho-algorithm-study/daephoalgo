import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

T = int(input())
for tc in range(T) :
    answer = 0
    stack = []
    str = list(input().strip())
    stack.append(str[0])
    for i in range(1, len(str)):
        
        if not stack:
            stack.append(str[i])
        elif stack[len(stack) - 1] != str[i]:
            stack.append(str[i])
        else :
            stack.pop()
    answer = len(stack)
        
    print(f'#{tc + 1} {answer}')