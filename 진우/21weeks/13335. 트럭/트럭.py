import sys
from collections import deque

input = sys.stdin.readline

# ===============================
# 입력
# ===============================
N, W, L = map(int, input().split())  # N: 트럭 수, W: 다리 길이, L: 다리 최대 하중
trucks = deque(map(int, input().split()))  # 트럭 무게 순서대로 큐에 저장

# ===============================
# 다리 초기화
# ===============================
bridge = deque()  # 다리를 시뮬레이션하는 큐
for _ in range(W):
    bridge.append(0)  # 다리 길이만큼 0으로 초기화 (빈 칸 의미)

time = 0  # 경과 시간

# ===============================
# 트럭이 다리를 모두 지나갈 때까지
# ===============================
while trucks:
    time += 1          # 1초 경과
    bridge.popleft()        # 다리 맨 앞 트럭(또는 빈 칸) 이동 → 큐에서 제거

    # 다음 트럭을 다리에 올릴 수 있는지 확인
    if sum(bridge) + trucks[0] <= L:  # 다리 위 총 무게 + 다음 트럭 무게 <= L
        bridge.append(trucks.popleft())  # 트럭 올리기
    else:
        bridge.append(0)  # 못 올리면 빈 칸(0) 올림

# ===============================
# 마지막 트럭이 다리를 완전히 지나갈 때까지
# ===============================
while bridge:
    time += 1
    bridge.popleft()  # 한 칸씩 이동

# ===============================
# 최종 시간 출력
# ===============================
print(time)
