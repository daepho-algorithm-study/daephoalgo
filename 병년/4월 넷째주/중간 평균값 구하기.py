import sys
import os
sys.stdin = open(os.path.join(os.path.dirname(__file__), "input.txt"))

T = int(input())

for tc in range(T):
    answer = 0
    nums = list(map(int, input().split()))
    nums.sort()
    for i in range(1, len(nums) - 1):
        
        answer += nums[i]
    result = round(answer / (len(nums) - 2))
    
    print(f'#{tc + 1} {result}')