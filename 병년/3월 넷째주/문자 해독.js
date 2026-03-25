const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  let idx = 0;
  let answer = 0;
  const [g, s] = input[idx++].split(" ").map(Number);
  const gCnt = Array(52).fill(0);
  const wCnt = Array(52).fill(0);

  const w = input[idx++];
  const S = input[idx++];
  const getIdx = (char) => {
    if (char >= "a") return char.charCodeAt(0) - 97;
    return char.charCodeAt(0) - 65 + 26;
  };
  for (let word of w) {
    wCnt[getIdx(word)]++;
  }

  for (let i = 0; i < g; i++) {
    gCnt[getIdx(S[i])]++;
  }

  const isSame = () => {
    for (let i = 0; i < 52; i++) {
      if (wCnt[i] !== gCnt[i]) return false;
    }
    return true;
  };
  if (isSame()) answer++;
  for (let i = g; i < s; i++) {
    gCnt[getIdx(S[i])]++;
    gCnt[getIdx(S[i - g])]--;
    if (isSame()) answer++;
  }
  console.log(answer);
};
solution(input);
