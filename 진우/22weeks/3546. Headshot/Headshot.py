# Headshot 문제 Python 버전

s = input().strip()  # 문자열 입력
length = len(s)

zero = 0  # 총 빈 칸 개수 (0)
cnt = 0   # 빈 칸 뒤에 빈 칸 있는 경우

for i in range(length):
    if s[i] == '0':
        zero += 1
        # 다음 칸도 0인지 확인 (원형 배열)
        if s[(i + 1) % length] == '0':
            cnt += 1

# 확률 비교 (분수 비교)
shoot = cnt * length      # shoot 확률 비교용 값
rotate = zero * zero      # rotate 확률 비교용 값

if shoot == rotate:
    print("EQUAL")
elif shoot > rotate:
    print("SHOOT")
else:
    print("ROTATE")
