function solution(maps) {
    var answer = 0;
    let visited = Array(maps.length).fill(false).map(()=> Array(maps[0].length).fill(false));
    
    let n = maps.length;
    let m = maps[0].length;
    
    const dx = [-1, 1, 0, 0]
    const dy = [0, 0, -1, 1]
    
    let queue = []
    queue.push([0, 0])
    visited[0][0] = true
    
    
    
    while(queue.length) {
        let [x, y] = queue.shift();
        
        for (var i = 0; i < 4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || maps[nx][ny] === 0 || visited[nx][ny]) {
                continue
            }
            visited[nx][ny] = true
            maps[nx][ny] = maps[x][y] + 1;
            queue.push([nx, ny]);
        }
    }
    return maps[n - 1][m - 1] > 1 ? maps[n - 1][m - 1] : -1;
}