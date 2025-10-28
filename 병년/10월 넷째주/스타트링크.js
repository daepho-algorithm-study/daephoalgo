const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [F, S, G, U, D] = input[0].split(" ").map(Number);
  const visited = Array.from({ length: 100100 }, () => false);

  const BFS = () => {
    let queue = [[S, 0]];
    visited[S] = true;
    let head = 0;
    while (queue.length > head) {
      let [cur, time] = queue[head++];
      if (cur === G) return time;

      const next = [cur + U, cur - D];

      for (let i = 0; i < next.length; i++) {
        if (!visited[next[i]] && 1 <= next[i] && next[i] <= F) {
          visited[next[i]] = true;
          queue.push([next[i], time + 1]);
        }
      }
    }
    return "use the stairs";
  };
  const result = BFS();
  console.log(result);
};
solution(input);
