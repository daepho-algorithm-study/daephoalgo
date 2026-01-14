import sys
input = sys.stdin.readline   # 빠른 입력을 위한 설정

# 타일의 길이 N 입력
N = int(input())

# DP 배열 생성 (0번부터 N번까지 사용)
arr = [0] * (N + 1)

# 초기값 설정
# 길이가 0일 때 경우의 수: 1
# 길이가 1일 때 경우의 수: 1
arr[0] = arr[1] = 1

# 점화식을 이용한 반복문 계산
# arr[n] = arr[n-1] + arr[n-2]
# 값이 커지므로 15746으로 나눈 나머지를 저장
for i in range(2, N + 1):
    arr[i] = (arr[i - 1] + arr[i - 2]) % 15746
    
# 길이가 N일 때 만들 수 있는 경우의 수 출력
print(arr[N])
