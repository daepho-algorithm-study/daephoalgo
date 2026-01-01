function solution(tickets) {
    var answer = [];
    var len = tickets.length;
    var visited = Array(len).fill(false);
    
    const dfs = (routes) => {
        // 전체 경로 탐색 했을 경우 마지막에 추가
        if (routes.length === len + 1) answer.push(routes);
        // 이전 가장 마지막 값
        const last = routes[routes.length -1]
        for (var i = 0; i < tickets.length; i++) {
            // 경로의 시작점과 끝 점
            const [start, end] = tickets[i]
            // 만약 아직 방문하지 않았고, 이전 경로의 마지막과 현재 경로의 값이 똑같으면
            if (!visited[i] && start === last) {
                // 방문 체크 하고
                visited[i] = true;
                // 다음 경로 탐색
                dfs([...routes, end]);
                visited[i] = false;
            }
        }
    }
    
    dfs(["ICN"])
    
    return answer.sort()[0];
}