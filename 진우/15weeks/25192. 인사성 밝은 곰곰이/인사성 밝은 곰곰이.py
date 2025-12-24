# 중복 없는 인사 횟수를 계산하는 프로그램

N = int(input())  # 채팅 로그의 총 개수 입력

users = set()     # 현재 채팅방에서 등장한 사용자 저장 (중복 자동 제거)
cnt = 0           # 전체 인사 횟수(정답)

for _ in range(N):
    user = input().strip()  # 사용자 이름 또는 "ENTER" 입력

    # 새로운 채팅방이 시작되는 경우
    if user == "ENTER":
        # 이전 채팅방에서 인사한 사람 수 누적
        cnt += len(users)

        # 다음 채팅방을 위해 사용자 목록 초기화
        users.clear()
    else:
        # 현재 채팅방에 사용자 추가
        # 이미 존재하면 set 특성상 자동으로 무시됨
        users.add(user)

# 마지막 채팅방에서 인사한 사람 수 누적
cnt += len(users)

# 최종 결과 출력
print(cnt)
