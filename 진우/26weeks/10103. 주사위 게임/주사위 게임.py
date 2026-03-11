# CY와 SD의 초기 체력 설정
CY = 100  # 창영의 체력
SD = 100  # 상덕의 체력

# 라운드 수 입력
N = int(input())  # 입력된 라운드 수

# N번 반복 (각 라운드 처리)
for _ in range(N):
    x, y = map(int, input().split())  # x = CY, y = SD가 낸 숫자 입력

    if x > y:            # 창영이 상덕보다 숫자가 크면
        SD -= x          # 상덕 체력에서 창영 숫자만큼 차감
    elif x < y:          # 상덕이 창영보다 숫자가 크면
        CY -= y          # 창영 체력에서 상덕 숫자만큼 차감
    else:                # 숫자가 같으면 (비김)
        continue             # 체력 변화 없음

# 최종 체력 출력
print(CY)  # 창영 체력
print(SD)  # 상덕 체력