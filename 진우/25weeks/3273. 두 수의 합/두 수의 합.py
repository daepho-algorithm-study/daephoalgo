import sys

input = sys.stdin.readline  # 빠른 입력

# 배열 크기 입력
N = int(input())

# 배열 입력
arr = list(map(int, input().split()))

# 투포인터 사용을 위해 정렬
arr.sort()

# 목표 합 입력
x = int(input())

start = 0              # 시작 인덱스
end = N - 1            # 끝 인덱스
cnt = 0                # 조건을 만족하는 쌍의 개수

# 서로 다른 두 인덱스를 사용해야 하므로 start < end
while start < end:

    total = arr[start] + arr[end]

    # 두 수의 합이 목표값과 같으면
    if total == x:
        cnt += 1
        start += 1
        end -= 1

    # 합이 작으면 왼쪽 증가 (더 큰 값 필요)
    elif total < x:
        start += 1

    # 합이 크면 오른쪽 감소 (더 작은 값 필요)
    else:
        end -= 1

print(cnt)