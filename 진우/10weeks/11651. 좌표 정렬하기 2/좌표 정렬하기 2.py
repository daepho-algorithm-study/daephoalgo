N = int(input())  
# 좌표의 개수 입력

arr = []  
# 좌표를 저장할 리스트

# 좌표 입력받기
for _ in range(N):
    x, y = map(int, input().split())  
    # 한 줄에 입력된 x, y를 정수로 변환
    num = [y, x]  
    # y를 먼저 저장, x를 나중에 저장 → sort할 때 y 기준 먼저, y 같으면 x 기준으로 정렬
    arr.append(num)  
    # 리스트에 추가

arr.sort()  
# 기본 정렬: 
# 1) 첫 번째 요소(y) 기준 오름차순
# 2) 첫 번째 요소가 같으면 두 번째 요소(x) 기준 오름차순

# 정렬된 좌표 출력
for j in range(len(arr)):
    print(arr[j][1], arr[j][0])  
    # 출력 시 x, y 순서로 출력 (원래 좌표 순서)
