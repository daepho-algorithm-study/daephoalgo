const { group } = require("console");
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
  .split("\n")
  .map((line) => line.trim());

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]); // 6
  const arr = input[idx++].split(" ").map(Number); // [5, 2, 3, 4, 1, 2]

  const graph = {};

  // 이후 N개의 줄을 반복
  for (let i = 1; i <= N; i++) {
    const nums = input[idx++].split(" ").map(Number);
    const connected = nums.slice(1); // 연결된 구역 리스트
    graph[i] = connected;
  }

  const getCombinations = (arr, selectNum) => {
    if (selectNum === 1) return arr.map((v) => [v]);
    const results = [];
    arr.forEach((fixed, i, origin) => {
      const rest = origin.slice(i + 1);
      const combinations = getCombinations(rest, selectNum - 1);
      const attached = combinations.map((comb) => [fixed, ...comb]);
      results.push(...attached);
    });
    return results;
  };

  const bfs = (group) => {
    const visited = new Set();

    visited.add(group[0]);

    let queue = [group[0]];
    let head = 0;

    while (queue.length > head) {
      const cur = queue[head++];
      for (next of graph[cur]) {
        if (!visited.has(next) && group.includes(next)) {
          visited.add(next);
          queue.push([next]);
        }
      }
    }
    return visited.size === group.length;
  };
  const allAreas = Array.from({ length: N }, (_, i) => i + 1);
  let min = Infinity;

  for (let i = 1; i <= Math.floor(N / 2); i++) {
    const comb = getCombinations(allAreas, i);
    for (const groupA of comb) {
      const groupB = allAreas.filter((x) => !groupA.includes(x));

      if (bfs(groupA) && bfs(groupB)) {
        const sumA = groupA.reduce((acc, cur) => acc + arr[cur - 1], 0);
        const sumB = groupB.reduce((acc, cur) => acc + arr[cur - 1], 0);
        const diff = Math.abs(sumA - sumB);
        min = Math.min(min, diff);
      }
    }
  }
  console.log(min);
};

solution(input);
