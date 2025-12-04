# 소수 판별 함수
# x가 소수이면 True, 소수가 아니면 False 반환
def is_prime(x: int) -> bool:
    if x < 2:  # 0과 1은 소수가 아님
        return False

    # 2부터 √x까지 나누어 떨어지는 수가 있는지 검사
    i = 2
    while i * i <= x:
        if x % i == 0:  # 나누어 떨어지는 수가 존재하면 소수 아님
            return False
        i += 1
    return True  # 끝까지 나누어 떨어지지 않으면 소수

# n 이상 중에서 가장 가까운 소수를 반환
def next_prime(y: int) -> int:
    # 소수가 나올 때까지 y 증가시키며 검사
    while not is_prime(y):
        y += 1
    return y

# 메인 함수
if __name__ == "__main__":
    T = int(input())  # 테스트 케이스 개수 입력

    for _ in range(T):
        n = int(input())           # 숫자 입력
        print(next_prime(n))       # n 이상 가장 가까운 소수 출력
