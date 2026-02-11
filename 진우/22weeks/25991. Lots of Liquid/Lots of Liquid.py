n = int(input())  
# 입력될 실수의 개수 n을 정수로 받음

arr = list(map(float, input().split()))  
# 공백으로 구분된 n개의 실수를 입력받아 리스트(arr)에 저장

total = 0  
# 각 수의 세제곱 합을 저장할 변수

for i in range(n):
    total += arr[i] ** 3  
    # arr[i]의 세제곱을 total에 누적

print(total ** (1/3))  
# 세제곱합(total)의 세제곱근을 계산하여 출력
