N = input()  # 숫자를 문자열 형태로 입력받음 (예: "2143")

arr = []  # 각 자릿수를 저장할 리스트

# 입력된 문자열의 각 문자를 순회하며 정수로 변환하여 리스트에 추가
for i in range(len(N)):
    arr.append(int(N[i]))

# 숫자들을 내림차순으로 정렬
arr.sort(reverse=True)

# 정렬된 숫자들을 문자열로 변환하여 공백 없이 이어 붙여 출력
print("".join(map(str, arr)))
