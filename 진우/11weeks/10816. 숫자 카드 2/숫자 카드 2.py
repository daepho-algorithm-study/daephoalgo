import sys
input = sys.stdin.readline

# 상근이가 가진 카드 개수 입력
N = int(input())

# 상근이가 가진 카드 번호들을 한 줄에서 입력받아 리스트로 저장
N_cards = list(map(int, input().split()))

# 찾아야 할 카드 개수 입력
M = int(input())

# 찾아야 할 카드 번호들을 한 줄에서 입력받아 리스트로 저장
M_cards = list(map(int, input().split()))

# 카드 번호별 등장 횟수를 저장할 딕셔너리 (key: 카드 숫자, value: 등장 횟수)
card_count = {}

# 상근이가 가진 카드들의 등장 횟수를 딕셔너리에 기록
for num in N_cards:
    if num in card_count:       
        card_count[num] += 1    # 이미 있는 숫자는 개수 증가
    else:
        card_count[num] = 1     # 처음 등장하는 숫자는 1로 설정

# 출력할 결과를 담을 리스트
result = []

# M개의 숫자 각각에 대해 상근이가 몇 개 갖고 있는지 조회
for num in M_cards:
    if num in card_count:
        result.append(card_count[num])
    else:
        result.append(0)        # 없으면 0 추가

# 결과 리스트를 공백으로 구분해 출력
print(*result)
