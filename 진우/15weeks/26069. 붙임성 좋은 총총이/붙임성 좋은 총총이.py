import sys
input = sys.stdin.readline

N = int(input())  # 만남의 개수 입력

dance = set()                 # 춤을 추고 있는 사람들을 저장할 집합
dance.add("ChongChong")       # 처음부터 춤을 추고 있는 사람

# N번의 만남 정보를 처리
for _ in range(N):
    a, b = input().split()    # 두 사람의 이름 입력

    # 첫 번째 사람이 이미 춤을 추고 있다면
    if a in dance:
        # 두 번째 사람도 춤을 추게 됨
        dance.add(b)
    # 첫 번째 사람은 아니지만, 두 번째 사람이 이미 춤을 추고 있다면
    elif b in dance:
        # 첫 번째 사람도 춤을 추게 됨
        dance.add(a)
    # 둘 다 춤을 추고 있지 않다면 아무 일도 하지 않음

# 최종적으로 춤을 추고 있는 사람의 수 출력
print(len(dance))
