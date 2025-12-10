const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "dev/stdin"
      : path.join(__dirname, "input.txt")
  )
  .toString()
  .trim()
  .split("\n");

class AbsHeap {
  constructor() {
    this.heap = [];
  }

  compare(a, b) {
    const absA = Math.abs(a);
    const absB = Math.abs(b);

    if (absA === absB) return a < b;
    return absA < absB;
  }

  push(num) {
    let heap = this.heap;
    heap.push(num);

    if (heap.length > 0) {
      let childIdx = heap.length - 1;
      let parentIdx = Math.floor((childIdx - 1) / 2);

      while (childIdx !== 0 && this.compare(heap[childIdx], heap[parentIdx])) {
        [heap[childIdx], heap[parentIdx]] = [heap[parentIdx], heap[childIdx]];

        childIdx = parentIdx;
        parentIdx = Math.floor((childIdx - 1) / 2);
      }
    }
  }

  pop() {
    const heap = this.heap;

    if (heap.length === 0) return 0;
    if (heap.length === 1) return heap.pop();

    const top = heap[0];
    heap[0] = heap.pop();

    let parentIdx = 0;
    let leftIdx = 1;
    let rightIdx = 2;

    while (true) {
      let smallest = parentIdx;

      if (
        heap[leftIdx] !== undefined &&
        this.compare(heap[leftIdx], heap[smallest])
      ) {
        smallest = leftIdx;
      }

      if (
        heap[rightIdx] !== undefined &&
        this.compare(heap[rightIdx], heap[smallest])
      ) {
        smallest = rightIdx;
      }

      if (smallest === parentIdx) break;

      [heap[parentIdx], heap[smallest]] = [heap[smallest], heap[parentIdx]];

      parentIdx = smallest;
      leftIdx = parentIdx * 2 + 1;
      rightIdx = parentIdx * 2 + 2;
    }
    return top;
  }
}

const solution = (input) => {
  let idx = 0;
  const absHeap = new AbsHeap();
  const N = Number(input[idx++]);
  let result = "";
  for (let i = 0; i < N; i++) {
    let el = Number(input[idx++]);

    if (el == 0) result += absHeap.pop() + "\n";
    else absHeap.push(el);
  }
  console.log(result);
};

solution(input);
