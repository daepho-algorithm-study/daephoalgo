T = int(input())  # 테스트 케이스 개수 입력

for _ in range(T):  # 각 테스트 케이스 반복
    N, M = map(int, input().split())  # N: 선택할 개수, M: 전체 개수

    result = 1  # 결과 초기화

    # M C N 계산 (팩토리얼 없이 곱셈과 나눗셈으로 직접 계산)
    for i in range(1, N + 1):
        result = result * (M - N + i) // i  # //는 정수 나눗셈

    print(result)  # 결과 출력
