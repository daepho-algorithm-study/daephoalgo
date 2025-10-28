const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const [A, B] = input[0].split(" ").map(Number);
  const limit = 1000000000;

  const bfs = () => {
    let queue = [[A, 1]];
    let head = 0;

    while (head < queue.length) {
      const [cur, cnt] = queue[head++];

      if (cur === B) return cnt;

      let next = [cur * 2, parseInt(cur.toString() + "1")];
      for (let i = 0; i < 2; i++) {
        if (next[i] <= limit) {
          queue.push([next[i], cnt + 1]);
        }
      }
    }
    return -1;
  };

  console.log(bfs());
};

solution(input);
