const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  const N = Number(input[idx++]);
  const arr = [];
  for (let i = 0; i < N; i++) {
    arr.push(Number(input[idx++]));
  }
  const unionLev = (num) => {
    let union = 0;
    if (60 <= num && num < 100) {
      union = 1;
    } else if (100 <= num && num < 140) {
      union = 2;
    } else if (140 <= num && num < 200) {
      union = 3;
    } else if (200 <= num && num < 250) {
      union = 4;
    } else if (250 <= num) {
      union = 5;
    }
    return union;
  };
  let answer = 0;
  let sm = 0;

  if (42 <= N) {
    arr.sort((a, b) => b - a);
    let answer = 0;
    let sm = 0;

    for (let i = 0; i < 42; i++) {
      let union = unionLev(arr[i]);
      sm += arr[i];
      answer += union;
    }
    console.log(sm, answer);
    return;
  }
  for (let i = 0; i < arr.length; i++) {
    let union = unionLev(arr[i]);
    sm += arr[i];
    answer += union;
  }
  console.log(sm, answer);
};
solution(input);
