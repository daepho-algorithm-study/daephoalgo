function solution(new_id) {
    // 1, 2단계
    let answer = new_id.toLowerCase().match(/[a-z\d\-\_\.]/g);

    if (answer) {
        answer = answer.join('').replace(/\.{2,}/g, '.');

        // 4단계
        if (answer[0] === '.') answer = answer.slice(1);
        if (answer[answer.length - 1] === '.') answer = answer.slice(0, -1);
    } else {
        answer = '';
    }

    // 5단계
    if (answer.length === 0) answer = 'a';

    // 6단계
    if (answer.length >= 16) {
        answer = answer.slice(0, 15);
        if (answer[answer.length - 1] === '.') answer = answer.slice(0, -1);
    }

    // 7단계
    while (answer.length < 3) {
        answer += answer[answer.length - 1];
    }

    return answer;
}
