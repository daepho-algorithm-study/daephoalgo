a, b, c = map(int, input().split())

arr = [a, b, c]

arr.sort()  # 배열 정렬

# 가장 큰 변이 나머지 두 변 합보다 크면 조정
if arr[0] + arr[1] <= arr[2]:
    arr[2] = arr[0] + arr[1] - 1

result = sum(arr)

print(result)
