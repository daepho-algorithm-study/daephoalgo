S = input().strip()
n = len(S)
arr = set()  # 서로 다른 부분 문자열 저장

for i in range(n):       # 시작 위치
    word = ""           # 부분 문자열 누적 변수
    for j in range(i, n):   # 현재 끝 위치
        word += S[j]        # 한 글자씩 이어붙이기
        arr.add(word)       # set에 추가 (중복 자동 제거)

print(len(arr))
