N = int(input())  
# 정렬할 좌표의 개수 입력받기

arr = [list(map(int, input().split())) for _ in range(N)]
# N번 반복하면서 입력받은 두 정수를 [x, y] 형태의 리스트로 저장
# 예: "3 4" → [3, 4]
# arr는 [[x1, y1], [x2, y2], ...] 형태가 됨

arr.sort()
# 파이썬의 기본 정렬 방식 사용
# 1) x 기준 오름차순
# 2) x가 같으면 y 기준 오름차순
# → 문제에서 요구하는 정렬 기준과 동일함

for x, y in arr:
    print(x, y)
# 정렬된 좌표를 한 줄씩 출력
