N = int(input())  # 실제 스위치 개수

# 스위치 상태 입력 (1번부터 사용하기 위해 0을 앞에 추가)
arr = [0] + list(map(int, input().split()))

M = int(input())  # 학생 수

for _ in range(M):
    x, num = map(int, input().split())  # x: 성별, num: 학생 번호

    if x == 1:  # 남학생
        for j in range(num, N + 1, num):
            arr[j] ^= 1  # 0 ↔ 1 토글
    else:  # 여학생
        left = right = num
        # 좌우 대칭으로 같은 값이면 범위 확장
        while left > 1 and right < N and arr[left - 1] == arr[right + 1]:
            left -= 1
            right += 1
        for k in range(left, right + 1):
            arr[k] ^= 1  # 범위 내 스위치 토글

# 출력 (한 줄에 20개씩)
for i in range(1, N + 1):
    print(arr[i], end=' ')
    if i % 20 == 0:
        print()