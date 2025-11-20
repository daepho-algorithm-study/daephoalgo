import sys

# 빠른 입력 사용 (input()보다 훨씬 빠름)
input = sys.stdin.readline

N = int(input())

# 1~10000 등장 횟수를 저장하는 리스트
# cnt_arr[i] = 숫자 i가 몇 번 등장했는지 저장
cnt_arr = [0] * 10001

# 숫자 입력받으며 카운팅
for _ in range(N):
    x = int(input())
    cnt_arr[x] += 1
    # 숫자 x가 등장할 때마다 해당 위치의 카운트를 증가시킴

# 카운팅 배열 기반으로 정렬된 수 출력
for i in range(1, 10001):
    # cnt_arr[i]가 3이라면 숫자 i를 3번 출력해야 함
    for _ in range(cnt_arr[i]):
        sys.stdout.write(str(i) + "\n")
