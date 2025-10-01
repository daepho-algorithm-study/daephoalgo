T = int(input())

for tc in range(T):
    S = list(input().split())

    R = int(S[0])
    word = S[1]

    result = ""

    for i in range(len(word)):
        result += word[i] * R

    print(result)