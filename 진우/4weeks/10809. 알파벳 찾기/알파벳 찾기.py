S = list(input())

arr = "abcdefghijklmnopqrstuvwxyz"

num = [-1] * 26

for i in range(len(S)):
    if S[i] in arr and num[ord(S[i]) - ord("a")] == -1:
        num[ord(S[i]) - ord("a")] = i


print(*num)

