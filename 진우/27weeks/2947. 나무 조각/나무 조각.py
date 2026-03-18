import sys
input = sys.stdin.readline

# 5개의 정수를 입력받아 리스트로 저장
arr = list(map(int, input().split()))

# 정렬이 완료될 때까지 반복
while True:
    # 인접한 두 값을 비교 (버블 정렬 한 사이클)
    for i in range(4):
        # 앞의 값이 더 크면 자리 교환
        if arr[i] > arr[i + 1]:
            arr[i], arr[i + 1] = arr[i + 1], arr[i]

            # swap이 일어날 때마다 현재 배열 상태 출력
            print(*arr)

    # 배열이 [1, 2, 3, 4, 5]인지 확인
    if arr == [1, 2, 3, 4, 5]:
        break