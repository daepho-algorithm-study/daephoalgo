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
  let idx = 1;
  const T = Number(input[0]);
  let result = [];

  for (let tc = 0; tc < T; tc++) {
    const N = Number(input[idx++]);

    const graph = Array(N + 1).fill(0);

    // 부모 관계 입력
    for (let i = 0; i < N - 1; i++) {
      const [a, b] = input[idx + i].split(" ").map(Number);
      graph[b] = a;
    }

    // A, B 라인 읽기
    const [A, B] = input[idx + N - 1].split(" ").map(Number);

    // 다음 테스트케이스를 위해 idx 이동
    idx += N;

    // A 조상들 저장
    const set = new Set();
    const dfs1 = (a) => {
      if (a === 0) return;
      set.add(a);
      dfs1(graph[a]);
    };
    dfs1(A);

    // B를 위로 탐색
    let answer = null;
    const dfs2 = (b) => {
      if (b === 0) return;
      if (set.has(b)) {
        answer = b; // 공통 조상 발견
        return;
      }
      dfs2(graph[b]);
    };
    dfs2(B);

    result.push(answer);
  }

  console.log(result.join("\n"));
};

solution(input);
