const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(N) {
  const arr = Array.from({ length: N }, () => Array(N).fill(" "));
  const recursion = (row, col, n) => {
    if (n === 1) {
      arr[row][col] = "*";
      return;
    }
    const nn = n / 3;

    // 첫 줄
    recursion(row, col, nn);
    recursion(row, col + nn, nn);
    recursion(row, col + nn * 2, nn);

    // 둘째 줄 (중간은 비우기)
    recursion(row + nn, col, nn);
    recursion(row + nn, col + nn * 2, nn);

    // 셋째 줄
    recursion(row + nn * 2, col, nn);
    recursion(row + nn * 2, col + nn, nn);
    recursion(row + nn * 2, col + nn * 2, nn);

    /*
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        if (i === 1 && j === 1) continue;
        recursion(row+(nn*i), col+(nn*j), nn);
      }
    }
    */
  };

  recursion(0, 0, N);
  return arr.map((row) => row.join("")).join("\n");
}

console.log(solution(input[0]));
