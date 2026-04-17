import math
import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

T = int(input())
for tc in range(T) :
    p, a, b = map(int, input().split(" "))
    def binSearch(l,r,end) :
        cnt = 0
        while l <= r :
            mid = math.floor((l + r) / 2)
            
            cnt += 1
            
            if mid == end:
                return cnt
            if mid < end:
                l = mid
            elif mid > end:
                r = mid 
            
    answerA = binSearch(1, p, a)
    answerB = binSearch(1, p, b)
    if answerA < answerB : print(f"#{tc + 1 } A")
    elif answerB < answerA : print(f'#{tc + 1 } B')
    else : print(f'#{tc + 1 } 0')
    