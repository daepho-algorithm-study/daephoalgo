# Python3 버전

# 입력 속도 최적화를 위해 sys.stdin.readline 사용 가능
import sys
input = sys.stdin.readline

# N: 수열 길이, M: 나누는 수
N, M = map(int, input().split())

# 수열 입력
arr = list(map(int, input().split()))

# 나머지의 발생 횟수를 기록할 리스트
# remainder[r] = 지금까지 누적합 % M == r 인 지점의 개수
remainder = [0] * M

cnt = 0    # 조건을 만족하는 구간의 총 개수
sum_ = 0   # 현재까지의 누적합

for i in range(N):
    # 현재까지의 누적합 갱신
    sum_ += arr[i]

    # 누적합을 M으로 나눈 나머지 계산
    r = sum_ % M

    # [케이스 1] 0번 인덱스부터 현재까지의 합 자체가 M의 배수인 경우
    if r == 0:
        cnt += 1

    # [케이스 2] 이전 지점들 중 누적합의 나머지가 현재와 같은 지점 개수만큼 구간 추가
    # sum[j] % M == sum[i] % M → 구간합이 M의 배수
    cnt += remainder[r]

    # 현재 지점의 나머지 발생 횟수 증가
    remainder[r] += 1

# 결과 출력
print(cnt)