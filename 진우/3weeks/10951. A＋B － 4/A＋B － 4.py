while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
    except EOFError:   # 입력이 끝나면(EOF) 종료
        break
