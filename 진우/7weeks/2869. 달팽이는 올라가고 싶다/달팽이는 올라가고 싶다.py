# 입력
A, B, V = map(int, input().split())

# 마지막 날 전까지 필요한 일수 계산
x = (V - A) // (A - B)

# 나머지가 있으면 하루 더 필요
if (V - A) % (A - B) != 0:
    x += 1

# 마지막 날 포함
cnt = x + 1

# 출력
print(cnt)
