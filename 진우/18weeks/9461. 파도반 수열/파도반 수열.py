import sys
input = sys.stdin.readline

T = int(input())  # 테스트 케이스 개수 입력

for _ in range(T):
    N = int(input())  # 구할 파도반 수열 항 번호 입력

    # 파도반 수열 값을 저장할 배열 (0~100까지 사용)
    arr = [0] * 101

    # 초기값 설정
    arr[0] = 0       # 사용하지 않는 값
    arr[1] = 1       # P(1)
    arr[2] = 1       # P(2)
    arr[3] = 1       # P(3)

    # 점화식 적용
    # P(n) = P(n-2) + P(n-3)
    for i in range(4, N + 1):
        arr[i] = arr[i - 2] + arr[i - 3]

    # N번째 파도반 수열 값 출력
    print(arr[N])
