const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  for (let i = 0; i < 3; i++) {
    const [sh, sm, ss, eh, em, es] = input[i].split(" ").map(Number);

    const startSec = sh * 3600 + sm * 60 + ss;
    const endSec = eh * 3600 + em * 60 + es;

    let diff = endSec - startSec;
    if (diff < 0) {
      diff += 24 * 3600;
    }

    const h = Math.floor(diff / 3600);
    const m = Math.floor((diff % 3600) / 60);
    const s = diff % 60;

    console.log(`${h} ${m} ${s}`);
  }
};
solution(input);
