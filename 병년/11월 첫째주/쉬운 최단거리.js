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
    let dx = [-1, 1, 0, 0]
    let dy = [0, 0, -1, 1]
    let startX = 0
    let startY = 0
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (arr[i][j] === 2) {
                startX = i
                startY = j
            }
        }
    }
    const newArr = Array.from({ length: N }, (_, i) =>
  Array.from({ length: M }, (_, j) => (arr[i][j] === 0 ? 0 : -1))
);

    const bfs = () => {
        let queue = [[startX, startY, 0]]
        let head = 0

        newArr[startX][startY] = 0

        while(queue.length > head) {
            let [x, y, cnt] = queue[head++]

            for (let k = 0; k < 4; k++) {
                let nx = x + dx[k]
                let ny = y + dy[k]

                if (0 <= nx && nx < N && 0 <= ny && ny < M && newArr[nx][ny] === -1 && arr[nx][ny] !== 0) {
                    newArr[nx][ny] = cnt + 1
                    queue.push([nx, ny, cnt+1])
                }
            }
        }
    }
    bfs()

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (arr[i][j] !== 0 && newArr[i][j] === -1) {
                // 도달 불가 칸만 -1로 표시
                newArr[i][j] = -1
            }
    }
}


    for (let i = 0; i < N; i++) {
    console.log(newArr[i].join(' '));
}

}
solution(input)