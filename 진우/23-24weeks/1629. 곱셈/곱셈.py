# 빠른 거듭제곱 (분할정복, 탑다운) - a^b % c
def check(a: int, b: int, c: int) -> int:
    """
    a^b % c를 재귀적으로 계산하는 함수 (분할정복)
    탑다운 방식, 시간복잡도 O(log b)
    
    Args:
        a (int): 밑
        b (int): 지수
        c (int): 나머지
    Returns:
        int: a^b % c
    """
    # 종료 조건: 지수가 0이면 a^0 = 1
    if b == 0:
        return 1

    # 재귀: 지수를 절반으로 줄여 계산
    # half = a^(b//2) % c
    half = check(a, b // 2, c)

    # 절반 결과를 제곱하고 나머지 연산
    result = (half * half) % c

    # 지수가 홀수이면 남은 한 번 곱해주기
    if b % 2 == 1:
        result = (result * a) % c

    # 최종 결과 반환
    return result


A, B, C = map(int, input().split())

# 재귀 호출로 계산 후 출력
print(check(A, B, C))