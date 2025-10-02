function solution(n) {
    var answer = [...String(n)];
    return Number(answer.sort((a,b) => b - a).join(''));
}