const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
    const [N, M] = input[0].split(" ").map(Number)
    let arr = input.slice(1).map((line) => line.split(" ").map(Number));

    const dx = [-1, 1, 0, 0]
    const dy = [0, 0, -1, 1]

    // 빙산 녹이기
    const melt = () => {
        // 원본 배열에서 변경하는 것이 아닌 새롭게 배열 생성
        const melted = Array.from({ length: N }, () => Array(M).fill(0));

        // 델타를 이용하여 인접한 바다의 개수 찾기
        for (let i = 0; i < N; i++) {
            for (let j = 0; j < M; j++) {
                if (arr[i][j] > 0) {
                    let sea = 0
                    for (let k = 0; k < 4; k++) {
                        let nx = i + dx[k]
                        let ny = j + dy[k]

                        if (0 <= nx && nx < N && 0 <= ny && ny < M && arr[nx][ny] === 0) {
                            sea++
                        }
                    }
                    // 현재 위치의 빙산 녹이기
                    melted[i][j] = Math.max(arr[i][j] - sea, 0)
                }
            }
        }
        // 원본 배열에 재할당
        arr = melted
    }

    // BFS 함수
    const bfs = (x, y, visited) => {
        let queue = [[x, y]]
        let head = 0;
        visited[x][y] = true;

        while (queue.length > head) {
            const [cx, cy] = queue[head++]

            for (let k = 0; k < 4; k++) {
                let nx = cx + dx[k]
                let ny = cy + dy[k]

                // 빙산의 덩어리 세기
                if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny] && arr[nx][ny] > 0) {
                    visited[nx][ny] = true
                    queue.push([nx, ny])
                }
            }
        }

    }
    // 결과값
    let result = 0
    while(true) {
        // 빙산의 덩어리 세기
        let cnt = 0;
        // 방문 체크 배열
        let visited = Array.from({ length: N }, () => Array(M).fill(false));
        for (let i = 0; i < N; i++) {
            for (let j = 0; j < M; j++) {
                // 빙산 덩어리 세기
                if (arr[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j, visited)
                    cnt++
                }
            }
        }
        // 빙산의 개수가 2개 이상일 경우
        if (cnt >= 2) {
            // 결과 return
            console.log(result)
            return
        }

        if (cnt === 0) {
            console.log(0)
            return
        }
        // 빙산 녹이기
        melt()
        result++
    }
}
solution(input)