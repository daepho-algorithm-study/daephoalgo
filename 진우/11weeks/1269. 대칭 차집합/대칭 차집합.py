# 두 집합의 원소 개수를 입력받는다. 
A, B = map(int, input().split())  

# 집합 A의 원소들을 한 줄로 입력받아 set으로 저장
A_set = set(map(int, input().split()))  

# 집합 B의 원소들을 한 줄로 입력받아 리스트로 저장
B_list = list(map(int, input().split()))

cnt = 0  # 교집합에 속하는 원소의 개수를 저장할 변수

# B의 각 원소가 A에 포함되는지 확인
for i in range(B):
    if B_list[i] in A_set:  # 포함되면
        cnt += 1            # 교집합 크기 증가

# 대칭 차집합 크기 계산
# 대칭 차집합 = (A ∪ B) - (A ∩ B) = |A| + |B| - 2 * |A ∩ B|
result = A + B - 2 * cnt

# 결과 출력
print(result)
