# N: 바구니 개수, M: 바구니 교환 횟수 입력
N, M = map(int, input().split())

# 1번 바구니부터 N번 바구니까지 번호를 차례대로 담은 리스트 생성
box = []
for x in range(1, N + 1):
    box.append(x)

# M번 동안 바구니의 위치를 서로 교환
for tc in range(M):
    # 교환할 두 바구니의 번호 i, j 입력
    arr = list(map(int, input().split()))
    i = arr[0]
    j = arr[1]

    # 현재 i번째와 j번째 바구니에 들어 있는 공 번호를 각각 저장
    x = box[i - 1]  # 파이썬은 0부터 인덱싱하므로 i-1
    y = box[j - 1]

    # 두 바구니의 공을 서로 교환
    box[i - 1] = y
    box[j - 1] = x

# 최종적으로 각 바구니에 들어 있는 공 번호를 공백으로 구분해 출력
print(*box)
