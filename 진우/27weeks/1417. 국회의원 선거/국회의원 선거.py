import sys
import heapq

# 입력 속도 향상
input = sys.stdin.readline

# 후보자 수 입력
N = int(input())

# 다솜이(1번 후보)의 현재 표 수
one = int(input())

# 힙(우선순위 큐) 생성
# Python heapq는 최소 힙이므로 음수를 넣어 최대 힙처럼 사용
q = []

# 나머지 후보들의 표 입력
for _ in range(N - 1):
    p = int(input())
    
    # 음수로 넣어서 최대 힙처럼 사용
    heapq.heappush(q, -p)

# 표 매수 횟수
cnt = 0

# 힙이 빌 때까지 반복
while q:
    
    # 가장 표가 많은 후보
    # 음수로 저장했기 때문에 다시 음수로 바꿔줌
    top = -heapq.heappop(q)

    # 그 후보가 다솜이보다 표가 많거나 같으면
    if top >= one:
        
        # 그 후보 표 1 감소
        top -= 1
        
        # 다시 힙에 넣기
        heapq.heappush(q, -top)
        
        # 다솜이 표 +1
        one += 1
        
        # 매수 횟수 증가
        cnt += 1

# 매수 횟수 출력
print(cnt)