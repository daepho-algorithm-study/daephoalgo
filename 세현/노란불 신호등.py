def solution(signals):
    N = len(signals)
    cycles = [0 for _ in range(N)]
    yellow_starts = [0 for _ in range(N)]
    yellow_ends = [0 for _ in range(N)]
    
    for i in range(N):
        cycles[i] = sum(signals[i])
        yellow_starts[i] = signals[i][0] + 1
        yellow_ends[i] = signals[i][0] + signals[i][1]

#   아래 코드 틀림
#     for i in range(N-1):
#         for j in range(i+1, N):
#             if cycles[i] == cycles[j] and (yellow_ends[i] < yellow_starts[j] or yellow_ends[j] < yellow_starts[i]): return -1
    
#     t = 1
#     while True:
#         flag = True
#         for i in range(N):
#
#             _t = t % cycles[i] if t % cycles[i] > 0 else t 
#
#             if _t < yellow_starts[i] or _t > yellow_ends[i]:
#                 flag = False
#                 break
#         if flag:
#             return t
#         t += 1
    
    # 최대공약수 구하기
    def _gcd(a, b):
        return a if b == 0 else _gcd(b, a % b)
    
    # 최소공배수 구하기
    def _lcm(a, b):
        return (a * b) // _gcd(a, b)
    
    lcm = 1
    for i in range(N):
        lcm = _lcm(lcm, cycles[i])
    
    # 최소공배수 까지만 검사(최소공배수 시간 내에 겹치는 구간 없으면 영원히 없음)
    for t in range(1, lcm+1):
        flag = True
        for i in range(N):
            
            # 시간은 주기를 넘어설 필요가 없기 때문에 모드 연산을 해줌
            # 다음 주기의 노란불 범위(/cycle + start/ ~ /cycle + end/)를 cycle로 mod해서 start ~ end로 맞추기
            _t = t % cycles[i] if t % cycles[i] > 0 else t 

            if _t < yellow_starts[i] or _t > yellow_ends[i]:
                flag = False
                break
        if flag:
            return t
    
    return -1
   
    
        
    