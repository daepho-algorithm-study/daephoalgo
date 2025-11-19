n = int(input())
words = []

for _ in range(n):
    words.append(input())

words = list(set(words))

words.sort()             # 먼저 사전순 정렬
words.sort(key=len)      # 길이 기준으로 다시 정렬

for w in words:
    print(w)
