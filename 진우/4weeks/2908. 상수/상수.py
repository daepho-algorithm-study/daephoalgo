A, B = input().split()

# 문자열 뒤집기
x = A[::-1]
y = B[::-1]

# 뒤집은 문자열 비교 후 출력
if x > y:
    print(x)
else:
    print(y)
