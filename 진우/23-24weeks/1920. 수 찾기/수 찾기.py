import sys
input = sys.stdin.readline

# 이진 탐색 함수
# a: 찾고 싶은 값
# A: 정렬된 리스트 (전역 변수로 사용)
def binary_search(a):
    left = 0                  # 탐색 범위의 시작 인덱스
    right = len(A) - 1        # 탐색 범위의 끝 인덱스

    # 탐색 범위가 남아있는 동안 반복
    while left <= right:
        mid = (left + right) // 2   # 중간 인덱스 계산

        # 중간 값이 찾는 값이면 존재
        if a == A[mid]:
            return 1
        # 찾는 값이 중간 값보다 크면 오른쪽 절반 탐색
        elif a > A[mid]:
            left = mid + 1
        # 찾는 값이 중간 값보다 작으면 왼쪽 절반 탐색
        else:
            right = mid - 1

    # 끝까지 못 찾았으면 존재하지 않음
    return 0


# 수의 개수 입력
N = int(input())

# 수열 입력
A = list(map(int, input().split()))

# 이진 탐색을 위해 반드시 정렬
A.sort()

# 탐색할 값의 개수 입력
M = int(input())

# 찾고 싶은 값들 입력
x = list(map(int, input().split()))

# 각 값에 대해 이진 탐색 수행
for i in range(M):
    print(binary_search(x[i]))