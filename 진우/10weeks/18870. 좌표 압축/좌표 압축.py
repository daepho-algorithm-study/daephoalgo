# 입력 개수
N = int(input())

# 원래 배열 입력
arr = list(map(int, input().split()))

# 1. 중복 제거 후 정렬
sorted_arr = list(set(arr))
sorted_arr.sort()  # 오름차순 정렬

# 2. 값 → 압축 값 매핑
compress = {}
for idx, value in enumerate(sorted_arr):
    compress[value] = idx  # 값(value)에 0부터 시작하는 인덱스(idx) 지정

# 3. 압축된 값 출력
for x in arr:
    print(compress[x], end=" ")
