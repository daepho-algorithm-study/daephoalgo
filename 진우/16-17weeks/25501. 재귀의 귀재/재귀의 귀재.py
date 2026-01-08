# 재귀 함수가 호출된 횟수를 저장하는 전역 변수
cnt = 0

# 문자열 s의 양 끝(l, r)을 비교하며 팰린드롬 여부를 재귀적으로 판단하는 함수
def recursion(s, l, r):
    global cnt          # 전역 변수 cnt를 사용하겠다고 선언
    cnt += 1            # recursion 함수가 호출될 때마다 카운트 증가

    # 종료 조건 1: 왼쪽 인덱스가 오른쪽 인덱스를 넘거나 같아지면
    # 문자열의 중앙에 도달했으므로 팰린드롬 성립
    if l >= r:
        return 1

    # 종료 조건 2: 양쪽 문자가 다르면 팰린드롬이 아님
    elif s[l] != s[r]:
        return 0

    # 양쪽 문자가 같으면 한 칸씩 안쪽으로 이동하여 다시 검사
    else:
        return recursion(s, l + 1, r - 1)

# 문자열 전체에 대해 팰린드롬 여부를 검사하는 함수
def isPalindrome(s):
    global cnt          # 전역 cnt를 초기화하기 위해 선언
    cnt = 0             # 새로운 문자열 검사 전에 호출 횟수 초기화
    # 문자열의 처음(0)부터 끝(len(s) - 1)까지 검사 시작
    return recursion(s, 0, len(s) - 1)

# 테스트 케이스 개수 입력
T = int(input())

# T개의 문자열에 대해 팰린드롬 검사 수행
for _ in range(T):
    word = input()      # 검사할 문자열 입력

    # 팰린드롬 여부(1 또는 0)와 재귀 호출 횟수 출력
    print(isPalindrome(word), cnt)
