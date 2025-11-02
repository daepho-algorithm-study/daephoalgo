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
  const [N, K] = input[0].split(" ").map(Number);

  const temp = Array.from({ length: 1000001 }, () => 0);
  const visited = Array.from({ length: 1000001 }, () => false);

  const bfs = () => {
    let queue = [[N, 0]];
    let head = 0;

    while (queue.length > head) {
      const [cur, time] = queue[head++];

      if (cur === K) return time;

      for (let nx of [cur * 2, cur - 1, cur + 1]) {
        if (0 <= nx && nx <= 1000001 && !visited[nx]) {
          temp[nx] = cur;
          visited[nx] = true;

          queue.push([nx, time + 1]);
        }
      }
    }
  };

  let k = bfs();
  const solve = (num) => {
    const path = [];
    path.push(K);
    let before = temp[K];
    for (let i = 0; i < num; i++) {
      path.push(before);
      before = temp[before];
    }
    return path;
  };
  const path = solve(k);
  path.reverse();

  console.log(k);
  console.log(path.join(" "));
};
solution(input);
