N, B = map(int, input().split())

result = ""
while N > 0:
    r = N % B
    if r < 10:
        result += str(r)
    else:
        result += chr(r + 55)
    N //= B  # 몫으로 업데이트

print(result[::-1])  # 뒤집어서 출력