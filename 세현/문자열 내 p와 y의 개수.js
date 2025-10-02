function solution(s){
    var answer = true;
    let p = 0;
    let y = 0;
    [...s].forEach((c) => {
        if (c === 'p' || c === 'P') {
        p += 1;
    } else if (c === 'y' || c === 'Y') {
        y += 1;       
        }
    })
                  
    if (p !== y) {
        answer = false;
    }
    return answer;
}