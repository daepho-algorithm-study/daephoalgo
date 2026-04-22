function solution(park, routes) {
    
    const findStart = (n, m) => {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < m; j++) {
                if (park[i][j] === 'S') return [i, j];
            }
        }
    }
    
    const [n, m] = [park.length, park[0].length];
    let [ci, cj] = findStart(n, m);

    const di = {'N': -1, 'S': 1, 'E': 0, 'W': 0}
    const dj = {'N': 0, 'S': 0, 'E': 1, 'W': -1}
    
    for (const route of routes) {
        let isStop = false;
        let [ni, nj] = [ci, cj];
        const [dir, dist] = route.split(' ');
        for (let i = 0; i < Number(dist); i++) {
            ni += di[dir];
            nj += dj[dir];
            if (ni >= n || ni < 0 || nj >= m || nj < 0 || park[ni][nj] === 'X') {
                isStop = true
                break;
            }
        }
        if (isStop) continue;

        ci = ni;
        cj = nj;
    }
    
    return [ci, cj];
}