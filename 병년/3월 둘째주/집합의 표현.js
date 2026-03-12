const fs = require("fs");
const path = require("path");
const input = fs.readFileSync(0, "utf-8").toString().trim().split("\n");

const solution = (input) => {
  let idx = 0;
  const [N, M] = input[idx++].split(" ").map(Number);
  // 1. 부모 배열 생성
  const arr = Array.from({ length: N + 1 }, () => 0);
  // 2. 부모를 자기 자신으로 초기화
  for (let i = 0; i < +N + 1; i++) {
    arr[i] = i;
  }
  // 3. 루트 찾기
  const find = (a) => {
    if (a === arr[a]) return a;

    return (arr[a] = find(arr[a]));
  };
  // 4. 집합 합치기
  const union = (x, y) => {
    let x1 = find(x);
    let y1 = find(y);

    arr[x1] = y1;
  };

  for (let i = 1; i < M + 1; i++) {
    const [op, a, b] = input[idx++].split(" ").map(Number);
    if (op === 0) union(a, b);
    else {
      let x = find(a);
      let y = find(b);
      let answer = x === y ? "YES" : "NO";
      console.log(answer);
    }
  }
};
solution(input);
