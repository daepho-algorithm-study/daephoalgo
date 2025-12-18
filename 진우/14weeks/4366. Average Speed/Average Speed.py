km = 0.0          # 누적 거리 (km)
time1 = 0         # 이전 시간(초)
speed = 0         # 현재 속도 (km/h)

while True:
    try:
        # 입력을 한 줄 읽고 공백으로 분리
        # 예: "12:00:00 60" 또는 "12:30:00"
        line = input().split()
        time = line[0]  # 시간 부분(HH:MM:SS)

        # 시간 문자열을 시, 분, 초로 분리하여 정수로 변환
        h = int(time[0:2])
        m = int(time[3:5])
        s = int(time[6:8])

        # 현재 시간을 초 단위로 변환
        time2 = h * 3600 + m * 60 + s
        
        # 이전 시간부터 현재 시간까지 이동한 거리 계산
        # 시간 차(초) * 속도(km/h) / 3600 = km 단위 거리
        km += (time2 - time1) * speed / 3600

        # 현재 시간을 이전 시간으로 갱신
        time1 = time2

        # 속도 정보가 있는 경우 갱신
        if len(line) > 1:
            speed = int(line[1])
        else:
            # 속도 정보가 없는 경우 현재까지 누적 거리 출력
            print(f"{time} {km:.2f} km")

    except EOFError:
        # 입력이 더 이상 없으면 반복 종료
        break
