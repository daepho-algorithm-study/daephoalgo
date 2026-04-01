const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
// .map((line) => line.split("").map(Number));

// console.log(input);

class MinAbsHeap {
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

  _bubbleUp(i) {
    while (i > 0) {
      const p = this.parent(i);
      if (this._lower(this.arr[i], this.arr[p])) {
        [this.arr[p], this.arr[i]] = [this.arr[i], this.arr[p]]
        i = p;
      } else break;
    }
  }

  // 절댓값 같은 경우를 포함하는 비교 함수
  // 절댓값 다르면 그냥 비교하고 같으면 작은 쪽(음수) 를 true(최소)로 설정
  _lower(a, b) {
    if (Math.abs(a) !== Math.abs(b)) return Math.abs(a) < Math.abs(b);
    return a < b;
  }

  extractMin() {
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
      let minimum = i;  // 일단 현재 노드가 제일 작다고 가정
      const l = this.left(i);
      const r = this.right(i);


      if (l < n && this._lower(this.arr[l], this.arr[minimum])) minimum = l;

      if (r < n && this._lower(this.arr[r], this.arr[minimum])) minimum = r;
      
      // 자식 중에 나보다 작은 게 있다 = swap 필요
      if (minimum !== i) {
        [this.arr[minimum], this.arr[i]] = [this.arr[i], this.arr[minimum]];
        i = minimum; // 내려간 후 인덱스 갱신
      } else break; // 힙 조건 만족 = 종료
    }
  }
}

function solution(nums) {
  let answer = [];
  const heap = new MinAbsHeap();

  for (const num of nums) {
    
    if (num === 0) { 
      const output = heap.extractMin();
      answer.push(output ? output : 0) 
    } else heap.insert(num);
  } 
  return answer.join('\n').trim();
}
const nums = input.slice(1).map(Number);
console.log(solution(nums));
