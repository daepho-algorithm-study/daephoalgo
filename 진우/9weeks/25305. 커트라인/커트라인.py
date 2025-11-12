# N: 응시자 수, k: 커트라인 순위 입력
N, k = map(int, input().split())

# 점수 입력
scores = list(map(int, input().split()))

# 점수를 내림차순 정렬
scores.sort(reverse=True)

# k번째 점수 출력 (1-based index이므로 k-1)
print(scores[k - 1])
