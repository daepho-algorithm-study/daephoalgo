arr = [int(input()) for _ in range(3)]

total = sum(arr)

if total != 180:
    print("Error")
elif arr[0] == arr[1] == arr[2]:
    print("Equilateral")
elif arr[0] == arr[1] or arr[1] == arr[2] or arr[0] == arr[2]:
    print("Isosceles")
else:
    print("Scalene")
