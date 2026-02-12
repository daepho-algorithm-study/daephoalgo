const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("/n");

const solution = (input) => {
  const obj = {
    SONGDO: "HIGHSCHOOL",
    CODE: "MASTER",
    2023: "0611",
    ALGORITHM: "CONTEST",
  };

  console.log(obj[input]);
};

solution(input[0]);
