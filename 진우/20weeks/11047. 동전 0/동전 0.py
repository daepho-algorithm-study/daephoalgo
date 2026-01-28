import sys

input = sys.stdin.readline  # 입력 속도 향상

N, K = map(int, input().split())  # N: 동전 개수, K: 만들어야 할 금액

arr = [int(input()) for _ in range(N)]  # 동전 가치 리스트

cnt = 0  # 사용한 동전의 총 개수

# 가장 가치가 큰 동전부터 사용
for i in range(N - 1, -1, -1):
    cnt += K // arr[i]  # 해당 동전으로 사용할 수 있는 최대 개수
    K %= arr[i]        # 남은 금액 계산

print(cnt)  # 최종 동전 개수 출력
