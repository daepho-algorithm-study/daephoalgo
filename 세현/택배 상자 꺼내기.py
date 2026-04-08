def solution(n, w, num):
    n_mok = n // w
    n_nam = n % w
    num_mok = num // w
    num_nam = num % w
    
    # n의 몫과 num의 몫을 뺀 값 -> 나머지 제외 한 층 높이 차(+ 꺼내려는 상자도 개수에 포함)
    answer = n_mok - num_mok + 1
    # num의 나머지가 있다면 두 격차가 1개 줄어듦
    if num_nam > 0: answer -= 1
    
    # 0: 왼쪽, 1: 오른쪽
    n_dir, num_dir = 0, 0
    
    # 나머지가 있으면 몫+1 해서 방향을 판별해야 함
    if num_nam > 0:
        num_dir = (num_mok + 1) % 2
    else:
        num_dir = num_mok % 2
    if n_nam > 0:
        n_dir = (n_mok + 1) % 2
    else:
        n_dir = n_mok % 2
    
    # num의 나머지가 없고(그 층의 마지막 자리 일 떄) n의 나머지가 있을 때
    if num_nam == 0 and n_nam > 0:
        # 방향이 다르면 무조건 위에 1개 더 쌓임
        if n_dir != num_dir: answer += 1 
    
    # num의 나머지가 있다면
    elif num_nam > 0:
        # 방향 같을 때
        if n_dir == num_dir:
            # n_nam이 num_nam 이상이면 1개 더 추가됨
            if n_nam >= num_nam: answer += 1
        # 방향 다르면
        else:
            # 두 택배 상자가 교차하면 1개 더 추가됨
            if n_nam + num_nam > w: answer += 1
    
    
    return answer