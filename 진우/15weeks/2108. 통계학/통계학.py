import sys
from math import floor

# 입력 최적화
input = sys.stdin.readline

N = int(input())  # 입력되는 수의 개수

arr = []          # 입력 숫자를 저장할 리스트
cnt = [0] * 8001  # -4000 ~ 4000 범위 숫자의 빈도 배열
sum_val = 0       # 합계 저장

# 입력과 동시에 합계 및 빈도 계산
for _ in range(N):
    num = int(input())
    arr.append(num)
    cnt[num + 4000] += 1  # 음수는 +4000으로 배열 인덱스 보정

# 1. 산술평균: sum / N 후 소수 첫째 자리 반올림
avg = sum(arr) / N
print(round(avg))

# 2. 중앙값: 정렬 후 중앙값
arr.sort()
print(arr[N // 2])

# 3. 최빈값 계산
mx = max(cnt)       # 최대 빈도
num = []
for i in range(8001):
    if cnt[i] == mx:
        num.append(i - 4000)  # 인덱스를 원래 숫자로 변환

# 최빈값 출력: 여러 개면 두 번째로 작은 값, 하나면 그 값
if len(num) > 1:
    print(num[1])
else:
    print(num[0])

# 4. 범위: 최대값 - 최소값
print(arr[-1] - arr[0])
