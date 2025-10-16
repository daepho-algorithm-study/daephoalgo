word = input()

re_word = word[::-1]

if word == re_word:
    print(1)
else:
    print(0)