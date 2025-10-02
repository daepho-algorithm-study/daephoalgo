function solution(num) {
    // 주의!! 음수이면서 홀수를 2로 % 연산하면 결과는 -1이 나옴!!
    return num % 2 === 0 ? "Even" : "Odd";
}