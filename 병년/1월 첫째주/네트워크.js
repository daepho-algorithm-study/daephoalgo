function solution(n, computers) {
    var answer = 0;
    var visited = Array.from(length = n, () => false);
    
    const dfs = (index) => {
        visited[index] = true;
        for (var i = 0; i < computers.length; i++) {
            if (!visited[i] && computers[index][i]) {
                dfs(i)
            }
        }
    }
    
    for (var i = 0; i < computers.length; i++) {
        if (!visited[i]) {
            dfs(i)
            answer++
        }
    }
    return answer;
}