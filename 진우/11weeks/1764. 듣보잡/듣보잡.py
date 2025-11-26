# N: 듣도 못한 사람 수
# M: 보도 못한 사람 수
N, M = map(int, input().split())

# 듣도 못한 사람들을 저장할 set
# set을 사용하면 중복 없이 저장되며,
# '이름 in set' 연산이 평균 O(1)로 매우 빠름
N_set = set()
for _ in range(N):
    name = input().strip()  # 개행 문자 제거
    N_set.add(name)         # set에 추가

# 듣보잡(듣도+보도 못한 사람)을 저장할 리스트
result = []

# 보도 못한 사람들을 입력받고,
# 듣도 못한 명단(set)에 존재하면 듣보잡으로 분류
for _ in range(M):
    name = input().strip()
    if name in N_set:        # set 조회 → 평균 O(1)
        result.append(name)

# 듣보잡 명단을 사전 순으로 정렬
result.sort()

# 듣보잡의 수 출력
print(len(result))

# 듣보잡 이름 출력
for name in result:
    print(name)
