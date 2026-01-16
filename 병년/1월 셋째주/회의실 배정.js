const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "input.txt")
  .toString()
  .trim()
  .split("\n");

const solution = (input) => {
  const N = Number(input.shift());
  const rooms = input.map((line) => line.split(" ").map(Number));

  // start 기준 정렬
  rooms.sort((a, b) => {
    if (a[1] === b[1]) return a[0] - b[0]; // end 같으면 start 오름차순
    return a[1] - b[1]; // end 오름차순
  });

  let cnt = 0;
  // 가장 최소값
  let lastEnd = -Infinity;

  for (const [start, end] of rooms) {
    // 현재 시작할 수 있는 회의실의 시간과 그 전에 끝난 회의실의 시간과 같다면
    if (lastEnd <= start) {
      // 카운팅
      cnt++;
      // 끝난 회의실 재할당
      lastEnd = end;
    }
  }

  console.log(cnt);
};

solution(input);
