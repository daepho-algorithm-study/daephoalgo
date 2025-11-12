def sugar(N):
    # 5kg 봉지를 최대한 많이 사용하는 경우부터 시도
    # N // 5는 N을 5로 나눈 몫 → 5kg 봉지의 최대 개수
    for x in range(N // 5, -1, -1):  
        # 5kg 봉지 x개 사용 후 남은 설탕의 양
        bags = N - (5 * x)
        
        # 남은 설탕이 3으로 나누어 떨어질 경우
        if bags % 3 == 0:
            y = bags // 3  # 3kg 봉지의 개수 계산
            return x + y   # 5kg 봉지 개수(x) + 3kg 봉지 개수(y)
    
    # 어떤 조합으로도 정확히 N을 만들 수 없는 경우
    return -1


# 사용자 입력 받기
N = int(input())

# 함수 호출 후 결과 저장
result = sugar(N)

# 최소 봉지 개수 출력 (불가능하면 -1 출력)
print(result)
