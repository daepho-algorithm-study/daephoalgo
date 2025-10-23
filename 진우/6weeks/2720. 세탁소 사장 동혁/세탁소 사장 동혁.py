T = int(input())

for _ in range(T):
    money = int(input())

    q = money // 25
    money %= 25

    d = money // 10
    money %= 10

    n = money // 5
    money %= 5

    p = money // 1
    money %= 1

    print(q, d, n, p)
