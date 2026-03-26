import sys
input = sys.stdin.readline

# 전체 회의 개수
I = int(input())

# (종료 시간, 시작 시간) 형태로 저장할 리스트
time = []

# 입력 받기
for _ in range(I):
    s, e = map(int, input().split())
    
    # 정렬 기준을 위해 (끝나는 시간, 시작 시간) 순으로 저장
    time.append((e, s))

# 1단계: 종료 시간 기준 오름차순 정렬
# 종료 시간이 같으면 시작 시간 기준으로 자동 정렬됨
time.sort()

cnt = 0   # 선택된 회의 개수
now = -1  # 현재 회의가 끝난 시간 (초기값은 매우 작은 값)

# 2단계: 그리디 선택
for end, start in time:
    
    # 현재 회의 시작 시간이 이전 회의 끝난 시간보다 같거나 늦으면 선택
    if now <= start:
        cnt += 1      # 회의 선택
        now = end     # 현재 기준 시간을 해당 회의 종료 시간으로 갱신

# 결과 출력
print(cnt)