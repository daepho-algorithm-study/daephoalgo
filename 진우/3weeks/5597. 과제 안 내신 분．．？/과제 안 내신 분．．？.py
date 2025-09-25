num = [0] * 31  # 1~30번을 사용하기 위해 31칸 (0은 안 씀)

for _ in range(28):
    n = int(input())
    num[n] = 1  # 해당 번호를 제출 표시

for i in range(1, 31):
    if num[i] == 0:  # 제출 안 한 학생 출력
        print(i)
