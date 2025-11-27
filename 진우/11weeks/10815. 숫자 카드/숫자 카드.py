# N: num 리스트에 들어갈 숫자의 개수 입력
N = int(input())

# num: N개의 숫자를 입력받아 집합(set)으로 변환
# set으로 만들면 'in' 연산이 O(1) → 탐색 속도 최적화
# ----------------------------------
# in 연산은 리스트 전체를 처음부터 끝까지 순차 탐색
# set은 내부적으로 해시 테이블(Hash Table) 구조 사용
# in 연산 시 해시값으로 바로 위치를 찾음
#-----------------------------------
num = set(map(int, input().split()))

# M: 확인할 카드 숫자의 개수 입력
M = int(input())

# card: M개의 카드 숫자를 리스트로 입력받음
card = list(map(int, input().split()))

# 각 카드 숫자가 num 집합 안에 있는지 확인
for x in card:
    # x는 현재 반복에서 확인하고 있는 카드 숫자
    if x in num:
        print(1, end=" ")  # 존재하면 1 출력, 뒤에 공백 붙임
    else:
        print(0, end=" ")  # 존재하지 않으면 0 출력, 뒤에 공백 붙임

# 반복이 끝난 후 마지막 줄바꿈
print()
