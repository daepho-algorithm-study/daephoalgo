/* 아래 코드 메모리 터짐
const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

// 단순 브루트포스+정렬(NlogN)
function solution(N, matrix) {

  const arr = matrix[N-1].sort((a, b) => b - a);
  for (let i = N-2; i >= 0; i--) {
    for (let j = N-1; j >= 0; j--) {
      if (arr[N-1] < matrix[i][j]) {
        arr[N-1] = matrix[i][j];
        arr.sort((a, b) => b - a);
      }
    }
  }

  return arr[N-1];
}

const N = Number(input[0])
const matrix = input.slice(1).map((line) => line.split(' ').map(Number));
console.log(solution(N, matrix));
*/

const readline = require("readline");
const readone = readline.createInterface({
  input: process.platform === "linux"
    ? process.stdin
    : require("fs").createReadStream("./input.txt")
}); // 한 줄씩 읽고 바로 처리해야 됨

let N = null;
const minHeap = [];

const heapPush = (val) => {
  minHeap.push(val);
  let i = minHeap.length - 1;
  while (i > 0) {
    const p = ~~((i - 1) / 2);
    if (minHeap[p] > minHeap[i]) {

      /* 메모리 터짐
      [minHeap[p], minHeap[i]] = [minHeap[i], minHeap[p]]; 
      */

      let tmp = minHeap[p];
      minHeap[p] = minHeap[i];
      minHeap[i] = tmp;
      i = p;
    } else break;
  }
}

const heapPop = () => {
  const min = minHeap[0];
  const last = minHeap.pop();
  if (minHeap.length) {
    minHeap[0] = last;
    let i = 0;
    while (true) {
      let smallest = i;
      const l = 2 * i + 1, r = 2 * i + 2;
      if (l < minHeap.length && minHeap[l] < minHeap[smallest]) smallest = l;
      if (r < minHeap.length && minHeap[r] < minHeap[smallest]) smallest = r;
      
      if (smallest !== i) {

        /* 메모리 터짐
        [minHeap[smallest], minHeap[i]] = [minHeap[i], minHeap[smallest]];
        */

        let tmp = minHeap[smallest];
        minHeap[smallest] = minHeap[i];
        minHeap[i] = tmp;

        i = smallest;
      } else break;
    }
  }
  return min;
}

readone.on("line", (line) => {
  if (N === null) {
    N = Number(line.trim());
    return;
  }

  const tokens = line.trim().split(" ")
  for (const token of tokens) {
    const val = Number(token);
    if (minHeap.length < N) {
      heapPush(val);
    } else if (val > minHeap[0]) {
      heapPop();
      heapPush(val);
    }
  }
});

readone.on("close", () => {
  console.log(minHeap[0]);
})