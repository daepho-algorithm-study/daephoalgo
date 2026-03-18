# 카드 번호를 저장할 리스트 (0번은 사용하지 않기 위해 크기 21)
arr = [0] * 21

# 처음 카드 상태: 1 ~ 20
for i in range(1, 21):
    arr[i] = i   # arr[1] = 1, arr[2] = 2 ... arr[20] = 20

# 카드 구간 뒤집기 연산 10번 수행
for i in range(10):
    s, e = map(int, input().split())  # 뒤집을 시작 위치 s, 끝 위치 e 입력

    # Python 슬라이싱은 [start:end] 구조이며 end는 포함되지 않음
    # 그래서 e까지 포함하려면 e+1을 사용
    # arr[s:e+1] 부분을 뒤집어서 다시 넣는다
    arr[s:e+1] = arr[s:e+1][::-1]

# 최종 카드 상태 출력
for i in range(1, 21):
    print(arr[i], end=" ")