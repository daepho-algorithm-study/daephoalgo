def solution(n, m):
    answer = []
    
    # 최대 공약수 구하기 - 유클리드 호제법
    # 2개의 자연수 a, b에 대하여 (a, b)의 약수는 (b, a%b)의 약수와 같다.
    # b가 0이 아니게 될 떄 까지 반복하면 최대공약수가 됨
    def _gcd(a, b):
        return a if b == 0 else _gcd(b, a % b)
    
    # 두 수의 곱은 최대공약수와 최소공배수의 곱과 같음 
    # 즉, 두 수의 곱에서 최대공약수를 나누면 최대공배수를 얻을 수 있음
    def _lcm(a, b):
        return (a * b) // _gcd(a, b)
    
    answer.append(_gcd(n, m))
    answer.append(_lcm(n, m))
    
    return answer