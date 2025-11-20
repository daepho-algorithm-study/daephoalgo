import sys

# 빠른 입력 (sys.stdin.readline 사용)
N = int(sys.stdin.readline())

arr = []  # 빈 리스트 생성

# N개의 정수를 입력받아 리스트에 추가
for _ in range(N):
    x = int(sys.stdin.readline())  # 한 줄씩 입력받기
    arr.append(x)

# 리스트를 오름차순으로 정렬
arr.sort()

# join을 이용해 한 번에 출력 (빠른 출력)
print("\n".join(map(str, arr)))
