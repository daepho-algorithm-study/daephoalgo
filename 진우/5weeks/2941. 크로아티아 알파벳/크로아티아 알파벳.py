word = input().strip()
count = 0
i = 0

while i < len(word):
    # "dz=" 확인 (3글자)
    if i + 2 < len(word) and word[i:i+3] == "dz=":
        count += 1
        i += 3
    # 나머지 2글자 조합 확인
    elif i + 1 < len(word) and word[i:i+2] in ["c=", "c-", "d-", "lj", "nj", "s=", "z="]:
        count += 1
        i += 2
    else:
        count += 1
        i += 1

print(count)
