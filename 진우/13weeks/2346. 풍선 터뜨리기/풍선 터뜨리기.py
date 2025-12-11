N = int(input())  # 풍선의 개수
arr = list(map(int, input().split()))  # 풍선 안에 적힌 수들

# 풍선의 번호를 기억하는 리스트
num = list(range(1, N + 1))

result = []  # 터진 풍선의 순서를 저장할 리스트

i = 0  # 시작 위치는 첫 번째 풍선

while len(arr) > 0:
    result.append(num.pop(i))  # 현재 위치의 풍선 번호를 결과에 추가
    move = arr.pop(i)  # 현재 위치의 풍선을 터뜨리고, 그 값을 얻음

    if len(arr) == 0:  # 모든 풍선이 터졌으면 종료
        break

    # 다음 이동할 위치 계산
    if move > 0:
        i = (i + (move - 1)) % len(arr)
    else:
        i = (i + move) % len(arr)

# 결과 출력
print(*result)