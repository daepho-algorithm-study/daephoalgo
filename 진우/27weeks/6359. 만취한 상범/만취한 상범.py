import sys
input = sys.stdin.readline

T = int(input())  # 테스트 케이스 개수 입력

# T개의 테스트 케이스 반복 처리
for _ in range(T):
    n = int(input())  # 창문의 개수

    cnt = 0  # 최종적으로 열려 있는 창문의 개수

    # 1부터 n까지 반복하면서 완전제곱수 세기
    for i in range(1, n + 1):
        if i * i > n:  # i*i가 n보다 크면 더 이상 완전제곱수 없음 → 반복 종료
            break
        cnt += 1       # i*i가 n 이하이면 완전제곱수 → 카운트 증가

    print(cnt)        