# 빈 리스트 생성 (입력받은 수들을 저장)
arr = []

# 무한 루프를 돌면서 입력 받기
while True:
    try:
        # 사용자로부터 정수 입력을 받음
        n = int(input())
        arr.append(n)  # 입력받은 정수를 리스트에 추가

    except EOFError:
        # 더 이상 입력이 없을 경우 (Ctrl+D 또는 Ctrl+Z)
        break  # 반복문 종료

# 리스트를 오름차순 정렬
arr.sort()

# 모든 원소의 합을 구하고, 정수 나눗셈으로 평균 계산
avg = sum(arr) // len(arr)

# 중앙값 계산 (정렬 후 중앙 인덱스 값)
median = arr[len(arr) // 2]

# 결과 출력
print(avg)     # 평균 출력
print(median)  # 중앙값 출력
