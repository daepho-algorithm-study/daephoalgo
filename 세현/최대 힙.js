const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

class MaxHeap {
  constructor() {
    this.arr = [];
  }
  size() { return this.arr.length; }
  peek() { return this.arr.length ? this.arr[0] : null; }
  parent(i) { return ~~((i - 1) / 2); }
  left(i) { return 2 * i + 1; }
  right(i) { return 2 * i + 2; }

  insert(val) {
    this.arr.push(val);
    this._bubbleUp(this.arr.length - 1);
  }

  // 새로 추가된 노드를 부모와 비교하며 위로 올림
  // 부모보다 크면 교환 → 루트에 도달하거나 부모가 더 클 때까지 반복
  _bubbleUp(i) {
    while (i > 0) {
      const p = this.parent(i);
      if (this.arr[p] < this.arr[i]) {
        [this.arr[p], this.arr[i]] = [this.arr[i], this.arr[p]]
        i = p;
      } else break;
    }
  }

  extractMax() {
    if (!this.arr.length) return null;

    const max = this.arr[0]; // 루트 값

    const last = this.arr.pop(); // 최하단 노드값
    if (this.arr.length) {
      this.arr[0] = last;
      this._shiftDown(0);
    }

    return max;
  }

  _shiftDown(i) {
    const n = this.arr.length;
    while (true) {
      let largest = i;  // 일단 현재 노드가 제일 크다고 가정
      const l = this.left(i);
      const r = this.right(i);

      // 왼쪽 자식이 현재 노드보다 크면 largest 갱신
      if (l < n && this.arr[l] > this.arr[largest]) largest = l;
      // 오른쪽 자식이 현재 노드보다 크면 largest 갱신
      if (r < n && this.arr[r] > this.arr[largest]) largest = r;
      
      // 자식 중에 나보다 큰 게 있다 = swap 필요
      if (largest !== i) {
        [this.arr[largest], this.arr[i]] = [this.arr[i], this.arr[largest]];
        i = largest; // 내려간 후 인덱스 갱신
      } else break; // 힙 조건 만족 = 종료
    }
  }
}

function solution(nums) {
  let answer = [];
  const heap = new MaxHeap();
  for (const num of nums) {
    if (num > 0) { heap.insert(num) }
    else if (num === 0){ 
      const output = heap.extractMax();
      answer.push(output ? output : 0) }
  }
  return answer.join('\n').trim();
}
const nums = input.slice(1).map(Number);
console.log(solution(nums));
