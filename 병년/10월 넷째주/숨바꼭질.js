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
    const [N, K] = input.split(" ").map(Number);
    const visited = Array.from({ length: 100100 }, () => false);

    const bfs = () => {
        let queue = [[N, 0]]
        visited[N] = true
        while(queue.length > 0) {
            let [cur, time] = queue.shift()

            if (cur === K) return time
            let next = [cur - 1, cur + 1, cur * 2]
            for (let i = 0; i < 3; i++) {
                if (!visited[next[i]] && 0 <= next[i] && next[i] < 1000000) {
                    queue.push([next[i], time + 1])
                    visited[next[i]] = true
                }
            }
        }
    }
    console.log(bfs())
}

solution(input[0])