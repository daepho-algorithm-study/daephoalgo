N = int(input())  # 정수 N 입력

# 0!은 1이므로 바로 출력
if N == 0:
    print(1)
else:
    result = 1  # 팩토리얼 결과를 저장할 변수

    # 1부터 N까지 곱해서 N! 계산
    for i in range(1, N + 1):
        result *= i

    print(result)  # 결과 출력
