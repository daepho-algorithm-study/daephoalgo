# N: 나무의 개수
# M: 필요한 나무의 총 길이
N, M = map(int, input().split())

# 각 나무의 높이를 저장할 리스트
tree = list(map(int, input().split()))

# 나무 높이 중 최댓값 (절단 높이 탐색의 상한)
mx = max(tree)


def binary_search(tree, x):
    """
    이분 탐색 함수
    - tree : 각 나무의 높이 리스트
    - x    : 나무 높이의 최댓값 (절단 높이 탐색의 상한)
    - 반환값: 필요한 길이 M 이상을 얻을 수 있는 최대 절단 높이
    """

    left = 0        # 절단 높이의 최소값
    right = x       # 절단 높이의 최대값
    
    answer = 0      # 조건을 만족하는 최대 절단 높이 저장

    # 절단 높이에 대해 이분 탐색 수행
    while left <= right:
        mid = (left + right) // 2  # 현재 탐색 중인 절단 높이

        cnt = 0
        # cnt: 현재 절단 높이(mid)로 나무를 잘랐을 때
        #      얻을 수 있는 나무 길이의 총합
        #      파이썬은 정수 오버플로우가 없지만,
        #      C++의 long long에 해당하는 역할

        # 모든 나무를 순회하며 잘린 나무 길이 계산
        for h in tree:
            # 나무 높이가 절단 높이보다 클 경우만 나무를 얻을 수 있음
            if h >= mid:
                cnt += h - mid

        # 필요한 나무 길이 M 이상을 얻을 수 있는 경우
        if cnt >= M:
            answer = mid       # 현재 절단 높이는 가능
            left = mid + 1     # 더 높은 절단 높이가 가능한지 탐색
        else:
            right = mid - 1    # 절단 높이를 낮춰 다시 탐색

    return answer  # 조건을 만족하는 최대 절단 높이 반환


# 이분 탐색을 통해 최적의 절단 높이 출력
print(binary_search(tree, mx))