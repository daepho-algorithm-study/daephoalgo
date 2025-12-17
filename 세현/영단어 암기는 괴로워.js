const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(input) {
  const M = Number(input[0][input[0].length-1]);

  const words = new Map();
  for (const word of input.slice(1)) {
    if (word.length < M) continue;
    words.set(word, (words.get(word) || 0) + 1);
  }

  const flashcard = [...words.keys()].sort((a, b) => {
    // 빈도수 내림차순
    if (words.get(a) !== words.get(b)) {
        return words.get(b) - words.get(a);
    }
    // 길이 내림차순
    if (a.length !== b.length) {
        return b.length - a.length;
    }

    // 사전순 오름차순
    if (a < b) return -1;
    if (a > b) return 1;

  })

  return flashcard.join('\n');
}

console.log(solution(input));
