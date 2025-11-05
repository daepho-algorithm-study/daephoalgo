while True:
    a, b, c = map(int, input().split())

    if a == 0 and b == 0 and c == 0:
        break

    mx = max(a, b, c)
    total = a + b + c - mx

    if mx >= total:
        print("Invalid")  # 삼각형이 될 수 없음
    elif a == b == c:
        print("Equilateral")
    elif a == b or b == c or a == c:
        print("Isosceles")
    else:
        print("Scalene")
