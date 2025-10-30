function solution(skill, skill_trees) {
    var answer = 0;

    for (const st of skill_trees) {
        let queue = [...skill]
        let flag = true
        for (const ch of st) {
            if (queue.includes(ch)) {
                if (queue[0] === ch) {
                    queue.shift()
                } else {
                    flag = false
                    break;
                }
            }
        }
        if (flag) answer++
    }
    return answer;
}