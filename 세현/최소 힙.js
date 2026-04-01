const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

class MinHeap {
  constructor() {
    this.arr = [];
  }

  size() { return this.arr.length; }
  peek() { return this.arr.length ? this.arr[0] : null; }
  parent(i) { return ~~((i - 1) / 2); }
  left(i) { return i * 2 + 1; }
  right(i) { return i * 2 + 2; }

  insert(val) {
    this.arr.push(val);
    this._bubbleDown(this.arr.length - 1);
  }

  _bubbleDown(i) {
    while (i > 0) {
      const p = this.parent(i);
      if (this.arr[p] > this.arr[i]) {
        [this.arr[p], this.arr[i]] = [this.arr[i], this.arr[p]];
        i = p;
      } else break;

    }
  }

  extractMin() {
    if (!this.arr.length) return null;

    const min = this.arr[0];

    const last = this.arr.pop();

    if (this.arr.length) {
      this.arr[0] = last;
      this._shiftDown(0);
    }

    return min;
  }

  _shiftDown(i) {
    const n = this.arr.length;

    while (true) {
      let minimum = i;
      const l = this.left(i);
      const r = this.right(i);

      if (l < n && this.arr[minimum] > this.arr[l]) minimum = l;
      if (r < n && this.arr[minimum] > this.arr[r]) minimum = r;

      if (minimum !== i) {
        [this.arr[minimum], this.arr[i]] = [this.arr[i], this.arr[minimum]];
        i = minimum;
      } else break;
    }
  }
}

function solution(nums) {
  let answer = [];
  const heap = new MinHeap();
  for (const num of nums) {
    if (num > 0) { heap.insert(num) }
    else if (num === 0){ 
      const output = heap.extractMin();
      answer.push(output ? output : 0) }
  }
  return answer.join('\n').trim();
}
const nums = input.slice(1).map(Number);
console.log(solution(nums));
