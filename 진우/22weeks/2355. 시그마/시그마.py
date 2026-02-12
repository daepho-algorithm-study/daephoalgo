# 입력
A, B = map(int, input().split())  # 구간 시작(A)과 끝(B)

# A가 B보다 크면 서로 교환
if A > B:
    A, B = B, A

# 구간 길이 계산
length = B - A + 1

# 등차수열 합 공식 적용
# sum = (첫 항 + 마지막 항) * 항 개수 / 2
result = (A + B) * length // 2   # //는 정수 나눗셈

# 결과 출력
print(result)
