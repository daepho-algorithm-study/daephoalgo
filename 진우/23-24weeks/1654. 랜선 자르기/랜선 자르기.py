import sys
input = sys.stdin.readline

# K: 기존 랜선 개수, N: 필요한 랜선 개수
K, N = map(int, input().split())

# 기존 랜선 길이 입력
lan = []
mx = 0  # 가장 긴 랜선 길이
for _ in range(K):
    length = int(input())
    lan.append(length)
    mx = max(mx, length)  # 최대값 갱신

def binary_search(lan, max_len):
    """
    lan: 기존 랜선 길이 리스트
    max_len: 탐색 범위의 최대값 (가장 긴 랜선)
    
    가능한 최대 랜선 길이를 이진 탐색으로 반환
    """
    left = 1            # 랜선 최소 길이
    right = max_len     # 랜선 최대 길이
    answer = 0          # 조건 만족 시 최대 길이 저장

    while left <= right:
        mid = (left + right) // 2  # 현재 시도 길이

        cnt = 0
        # mid 길이로 잘랐을 때 만들 수 있는 랜선 개수 계산
        for l in lan:
            cnt += l // mid

        if cnt >= N:
            # N개 이상 만들 수 있으면 길이를 늘려서 더 큰 mid 탐색
            answer = mid
            left = mid + 1
        else:
            # N개 미만이면 길이를 줄임
            right = mid - 1

    return answer

# 최대 랜선 길이 계산 후 출력
print(binary_search(lan, mx))