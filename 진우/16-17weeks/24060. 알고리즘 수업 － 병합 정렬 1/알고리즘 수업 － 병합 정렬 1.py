K = 0          # K번째로 배열에 저장되는 값
cnt = 0        # 배열 저장 횟수 카운트
answer = -1    # K번째 저장값이 없으면 -1

# ---------------------------
# 병합 함수
# A[p..q]와 A[q+1..r]를 병합하여 A[p..r]을 오름차순으로 정렬
# ---------------------------
def merge(A, p, q, r):
    global cnt, answer

    i = p           # 왼쪽 배열 시작 인덱스
    j = q + 1       # 오른쪽 배열 시작 인덱스
    t = 0           # 임시 배열 tmp의 인덱스

    tmp = [0] * (r - p + 1)   # 병합할 구간 길이만큼 임시 배열 생성

    # 두 부분 배열을 비교하며 작은 값부터 tmp에 저장
    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            i += 1
        else:
            tmp[t] = A[j]
            j += 1
        t += 1

    # 왼쪽 배열에 남은 값이 있으면 tmp에 복사
    while i <= q:
        tmp[t] = A[i]
        i += 1
        t += 1

    # 오른쪽 배열에 남은 값이 있으면 tmp에 복사
    while j <= r:
        tmp[t] = A[j]
        j += 1
        t += 1

    # tmp 배열의 값을 다시 A[p..r]에 복사하면서 K번째 저장 확인
    i = p
    t = 0
    while i <= r:
        cnt += 1              # 저장할 때마다 카운트 증가
        if cnt == K:          # K번째 저장이면 answer에 기록
            answer = tmp[t]
        A[i] = tmp[t]         # 실제 A 배열에 값 저장
        i += 1
        t += 1

# ---------------------------
# 병합 정렬 함수
# A[p..r]을 오름차순 정렬
# ---------------------------
def merge_sort(A, p, r):
    if p < r:                  # 구간에 2개 이상 원소가 있어야 정렬 가능
        q = (p + r) // 2       # 중간 지점 계산
        merge_sort(A, p, q)    # 전반부 정렬
        merge_sort(A, q + 1, r)# 후반부 정렬
        merge(A, p, q, r)      # 병합

N, K = map(int, input().split())      # 배열 크기 N과 K번째 저장 위치 입력
A = list(map(int, input().split()))   # 정렬할 배열 입력

merge_sort(A, 0, N - 1)               # 병합 정렬 수행

print(answer)                         # K번째 저장 값 출력
