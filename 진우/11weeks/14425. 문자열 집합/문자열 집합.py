# S: 집합에 들어있는 문자열 수
# M: 확인할 문자열 수
S, M = map(int, input().split())

# 문자열을 저장할 집합 생성 (중복 제거, 탐색 빠름)
S_words = set()

# S개의 문자열 입력받아 집합에 추가
for _ in range(S):
    word = input()        # 한 줄씩 문자열 입력
    S_words.add(word)     # set에 추가 (중복 자동 제거)

cnt = 0  # 집합에 포함된 문자열 개수 카운트

# M개의 문자열 입력받아 집합에 존재 여부 확인
for _ in range(M):
    word = input()        # 확인할 문자열 입력

    # set에서 해당 문자열이 존재하면 cnt 증가
    if word in S_words:   # 'in' 연산: 평균 O(1)
        cnt += 1

# 최종 포함된 문자열 개수 출력
print(cnt)
