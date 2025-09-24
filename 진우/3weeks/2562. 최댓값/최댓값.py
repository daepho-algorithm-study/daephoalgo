arr = []
for _ in range(9):
    A = int(input())
    arr.append(A)

mx = max(arr)
for i in range(len(arr)):
    if arr[i] == mx:
        print(mx)
        print(i + 1)
        break
