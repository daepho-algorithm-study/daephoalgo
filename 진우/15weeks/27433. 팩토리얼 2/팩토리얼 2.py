# 팩토리얼을 계산하는 함수
def factorial(a):
    # 종료 조건: 0!은 1
    if a == 0:
        return 1
    
    # 재귀 호출
    # a! = a × (a-1)!
    return a * factorial(a - 1)


# 정수 입력 받기
N = int(input())

# 팩토리얼 계산 결과 출력
print(factorial(N))
