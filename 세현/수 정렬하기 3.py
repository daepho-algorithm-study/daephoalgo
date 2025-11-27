import sys

'''
# 이렇게 배열 하나하나 다 만들어서 풀면 메모리 초과남 

if sys.platform == "linux":
    input = sys.stdin.readlines
else:
    sys.stdin = open("input.txt", "r")
    input = sys.stdin.readlines

inpt = [int(e.strip()) for e in input()]
N = inpt[0]
nums = inpt[1:]
sorted_arr = [0]*N
mx = max(nums)
cnt_arr = [0] * (mx+1)

# 숫자 개수 세주기
for n in nums:
    cnt_arr[n] += 1

# 누적합 만들기
for i in range(1, mx+1):
    cnt_arr[i] += cnt_arr[i-1]

# 누적합의 요소가 원본 배열에서 정렬시킬 배열 요소의 인덱스가 됨
# stable 정렬을 위해 뒤쪽 요소부터 차례대로 정렬시킴
for j in range(N-1, -1, -1):
    sorted_arr[cnt_arr[nums[j]]-1] = nums[j]
    cnt_arr[nums[j]] -= 1

print('\n'.join(map(str, sorted_arr)))

그래서 카운팅 배열만 만들고 나머지는 바로 출력하도록 해야 함(메모리 아껴)

'''

# N개 숫자를 전부 배열로 가질 필요 없이 바로 출력
# 카운팅 배열을 누적합으로 만들 필요도 없음(몇개 있는지만 확인하면 됨)

N = int(input()) # 첫째 줄 개수
cnt = [0] * 10001 # 카운팅 배열 먼저 만들고

for _ in range(N): 
    num = int(input()) # 매번 줄마다 숫자 들어오는 대로
    cnt[num] += 1      # 그 숫자 개수 하나씩 증가

for num in range(1, 10001): # 숫자 범위를 모두 돌면서
    for _ in range(cnt[num]): # 그 숫자의 개수만큼 반복해서 출력
                              # 만약 개수가 0이면 반복문이 아예 돌지 않겠지?
        print(num)            # 파이썬은 이렇게 날먹으로 풀수밖에 없다(다른 방법 생각안남)