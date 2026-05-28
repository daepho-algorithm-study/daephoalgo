import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

def calc(s, stack):
    b = int(stack.pop())
    a = int(stack.pop())
    if s == "+" :
        return (a + b)
    elif s == "-" :
        return (a - b)
    elif s == "*" :
        return (a * b)
    elif s == "/" :
        return (a // b)
        


T = int(input())
for tc in range(T):
    result = []
    arr = input().split(" ")
    stack = []

    error = False
    for s in arr:
        if s == "." :
            if len(stack) != 1:
                error = True
            break
        if s in ["+", "-", "*", "/"] :
            if len(stack) < 2:
                error = True
                break
            stack.append(calc(s, stack))
        else:
            stack.append(int(s))
    if not error:
        print(f'#{tc + 1} {stack[0]}')
    else:
        print(f'#{tc + 1} error')