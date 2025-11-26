import sys
input = sys.stdin.readline

# N: 포켓몬 수, M: 문제에서 물어볼 횟수
N, M = map(int, input().split())

# 이름 → 번호 매핑용 딕셔너리
pokedex = {}

# 번호 → 이름 매핑용 리스트 (1번부터 사용하므로 N+1 크기)
num = [""] * (N + 1)

# 포켓몬 도감 데이터 입력
for i in range(1, N + 1):
    name = input().strip()  # 포켓몬 이름 입력
    pokedex[name] = i       # 이름으로 번호 찾기
    num[i] = name           # 번호로 이름 찾기

# 문제 질의 처리
for _ in range(M):
    name = input().strip()  # 입력(이름 또는 번호)

    # 첫 글자가 숫자면 → 번호로 간주
    if '0' <= name[0] <= '9':
        idx = int(name)     # 문자열 숫자를 정수로 변환
        print(num[idx])     # 번호에 해당하는 포켓몬 이름 출력
    else:
        # 숫자가 아니면 → 이름으로 간주
        print(pokedex[name])   # 이름에 해당하는 번호 출력
