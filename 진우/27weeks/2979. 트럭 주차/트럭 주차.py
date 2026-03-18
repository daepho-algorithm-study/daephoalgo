# Python3 버전 (인덱스 for 사용)
import sys
input = sys.stdin.readline

# 트럭 1, 2, 3대 요금 입력
A, B, C = map(int, input().split())

time = []  # 이벤트 리스트: (시간, +1=들어옴, -1=나감)

# 트럭 3대 입력
for _ in range(3):
    s, e = map(int, input().split())
    time.append((s, 1))   # 트럭 들어오면 +1
    time.append((e, -1))  # 트럭 나가면 -1

# 시간 기준으로 정렬
time.sort()

cnt = 0                 # 현재 주차된 트럭 수
prev = time[0][0]       # 이전 이벤트 시간
total = 0               # 총 요금

# 인덱스 방식으로 이벤트 순회
for i in range(len(time)):
    now = time[i][0]       # 현재 이벤트 시간

    duration = now - prev   # 이전 시간 ~ 현재 시간 구간 길이

    # 구간 동안 주차된 트럭 수에 따른 요금 계산
    if cnt == 1:
        total += duration * (1 * A)
    elif cnt == 2:
        total += duration * (2 * B)
    elif cnt == 3:
        total += duration * (3 * C)

    cnt += time[i][1]           # 트럭 들어오면 +1, 나가면 -1
    prev = now              # 기준 시간 업데이트

# 총 요금 출력
print(total)