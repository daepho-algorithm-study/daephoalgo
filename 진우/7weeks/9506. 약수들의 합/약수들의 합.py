while True:
    n = int(input())  # 정수 n 입력받기

    if n == -1:  # 입력값이 -1이면 반복문 종료 (프로그램 종료)
        break
    else:
        arr = []  # n의 약수를 저장할 리스트

        # 1부터 n-1까지 반복하면서 n의 약수 찾기
        # 완전수 판별에서는 자기 자신(n)은 제외해야 함
        for i in range(1, n):
            if n % i == 0:  # i가 n의 약수이면
                arr.append(i)  # 약수 리스트에 추가

        result = ""  # 출력용 문자열 변수

        # 완전수(perfect number) 판별
        # 완전수: 자기 자신을 제외한 약수의 합이 자기 자신과 같은 수
        if sum(arr) == n:
            # 약수들을 " + "로 연결해 표현
            for i in range(len(arr)):
                result += str(arr[i])  # 숫자를 문자열로 변환해 추가
                if i < len(arr) - 1:  # 마지막 항목 전까지만 ' + ' 추가
                    result += " + "
            
            # 예: 6 = 1 + 2 + 3
            print(f"{n} = {result}")
        else:
            # 완전수가 아닐 경우
            # 예: 12 is NOT perfect.
            print(f"{n} is NOT perfect.")
