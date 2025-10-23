arr = [list(input()) for _ in range(5)]

result = ""

mx_len = 0

for i in range(len(arr)):
    if len(arr[i]) > mx_len:
        mx_len = len(arr[i])

for j in range(mx_len):
    for k in range(5):
        if j < len(arr[k]):  # 인덱스 존재할 때만 접근
            result += arr[k][j]

print(result)