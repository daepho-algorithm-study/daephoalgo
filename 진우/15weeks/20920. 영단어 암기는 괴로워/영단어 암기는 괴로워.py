import sys
input = sys.stdin.readline

# 단어별 빈도 기록용 딕셔너리
cnt = {}

# 입력 처리
N, M = map(int, input().split())
words = set()  # 중복 제거용

for _ in range(N):
    word = input().strip()
    if len(word) >= M:        # 최소 길이 M 이상인 단어만 처리
        cnt[word] = cnt.get(word, 0) + 1
        words.add(word)

# set -> list 변환
wordbook = list(words)

# 정렬: 
# 1. 빈도 내림차순
# 2. 길이 내림차순
# 3. 사전순 오름차순
wordbook.sort(key=lambda w: (-cnt[w], -len(w), w))

# 출력
for w in wordbook:
    print(w)
