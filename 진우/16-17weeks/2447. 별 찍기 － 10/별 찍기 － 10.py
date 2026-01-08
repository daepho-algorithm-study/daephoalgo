# ---------------------------
# n : 현재 블록 크기
# 반환 : n 길이의 문자열 리스트
# ---------------------------
def star(n):
    # [기저 조건]
    # 블록 크기가 1이면 별 하나만 있는 리스트 반환
    if n == 1:
        return ['*']

    # 이전 단계(1/3 크기) 블록 재귀 호출
    block = star(n // 3)

    # 새로운 블록 리스트 초기화
    arr = []

    # 1. 위쪽 1/3 블록: 이전 블록을 3번 반복
    for i in block:
        arr.append(i * 3)

    # 2. 가운데 1/3 블록: 이전 블록 + 공백 + 이전 블록
    for i in block:
        arr.append(i + ' ' * (n // 3) + i)

    # 3. 아래쪽 1/3 블록: 이전 블록을 3번 반복
    for i in block:
        arr.append(i * 3)

    # 완성된 n 크기 블록 반환
    return arr

N = int(input())         # 전체 칸토어 블록 크기 입력 (3^k)

result = star(N)         # 칸토어 패턴 생성

print('\n'.join(result)) # 리스트를 문자열로 합쳐서 출력
