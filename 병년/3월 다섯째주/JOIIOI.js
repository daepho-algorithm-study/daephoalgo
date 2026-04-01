const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const str = input[0];
  let window = str.slice(0, 3);

  let jCnt = 0;
  let iCnt = 0;

  if (window === "JOI") jCnt++;
  else if (window === "IOI") iCnt++;

  for (let i = 3; i < str.length; i++) {
    window = window.slice(1) + str[i];
    if (window === "JOI") jCnt++;
    else if (window === "IOI") iCnt++;
  }
  console.log(jCnt);
  console.log(iCnt);
};
solution(input);
