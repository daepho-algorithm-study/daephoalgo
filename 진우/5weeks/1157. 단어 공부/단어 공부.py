word = input().strip().upper()  # 입력받고 대문자로 변환

alpa = [0] * 26  # 알파벳 개수 저장용 리스트

# 각 알파벳 카운트
for c in word:
    alpa[ord(c) - ord('A')] += 1

# 최댓값 찾기
mx = max(alpa)
count = alpa.count(mx)

# 결과 출력
if count > 1:
    print("?")
else:
    result = chr(alpa.index(mx) + ord('A'))
    print(result)
