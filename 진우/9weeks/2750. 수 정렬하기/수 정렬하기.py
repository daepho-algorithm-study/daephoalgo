# 입력받을 수의 개수
N = int(input())

# 수들을 리스트로 입력받기
arr = [int(input()) for _ in range(N)]

# 오름차순 정렬
arr.sort()

# 정렬된 결과 출력
for num in arr:
    print(num)
