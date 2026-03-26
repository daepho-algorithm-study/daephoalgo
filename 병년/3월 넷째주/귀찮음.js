const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(process.platform === "linux" ? "dev/stdin" : path.join(__dirname, "input.txt"))
  .toString()
  .trim()
  .split("\n");
class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(num) {
    let heap = this.heap;
    heap.push(num);

    if (heap.length > 0) {
      let childIdx = heap.length - 1;
      let parentIdx = Math.floor((childIdx - 1) / 2);

      while (childIdx !== 0 && heap[parentIdx] > heap[childIdx]) {
        let [child, parent] = [heap[childIdx], heap[parentIdx]];

        heap[childIdx] = parent;
        heap[parentIdx] = child;

        childIdx = parentIdx;
        parentIdx = Math.floor((childIdx - 1) / 2);
      }
    }
  }

  popMin() {
    let heap = this.heap;

    if (heap.length === 0) return 0;
    if (heap.length === 1) return heap.pop();

    let min = heap[0];
    heap[0] = heap.pop();

    let parentIdx = 0;
    let leftChildIdx = parentIdx * 2 + 1;
    let rightChildIdx = parentIdx * 2 + 2;

    while ((heap[leftChildIdx] && heap[leftChildIdx] < heap[parentIdx]) || (heap[rightChildIdx] && heap[rightChildIdx] < heap[parentIdx])) {
      let parent = heap[parentIdx];
      let childIdx = leftChildIdx;

      if (heap[rightChildIdx] && heap[rightChildIdx] < heap[leftChildIdx]) {
        childIdx = rightChildIdx;
      }

      let child = heap[childIdx];

      heap[parentIdx] = child;
      heap[childIdx] = parent;

      parentIdx = childIdx;
      leftChildIdx = parentIdx * 2 + 1;
      rightChildIdx = parentIdx * 2 + 2;
    }
    return min;
  }
}

const solution = (input) => {
  let idx = 0;
  let N = Number(input[idx++]);
  const q = new MinHeap();
  const arr = input[idx++].split(" ").map(Number);
  for (let i = 0; i < arr.length; i++) {
    q.push(arr[i]);
  }
  let answer = 0;
  while (true) {
    if (N === 1) {
      break;
    }
    let a1 = q.popMin();
    let a2 = q.popMin();

    let sm = a1 + a2;
    let cost = a1 * a2;
    answer += cost;
    q.push(sm);
    N--;
  }
  console.log(answer);
};
solution(input);
