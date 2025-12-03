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
/**
 * 최대 힙
 *
 * JS 의 경우 힙 라이브러리가 존재하지 않기 때문에 클래스로 구현해야 함
 */
class MaxHeap {
  constructor() {
    this.heap = [];
  }
  /**
   *
   * 1. 배열 끝에 원소 추가
   * 2. 추가된 원소를 부모와 비교하여 swap 진행
   */
  push(num) {
    let heap = this.heap;
    // 원소 추가
    heap.push(num);
    /**
     * 새로 추가된 원소를 부모와 비교하며 위로 올라가기
     * childIdx = 새 원소의 인덱스 (heap.length - 1)
     * parentIdx = Math.floor((childIdx - 1) / 2)
     */
    if (heap.length > 1) {
      let childIdx = heap.length - 1;
      let parentIdx = Math.floor((childIdx - 1) / 2);
      // 루트에 도달하거나 부모가 더 크거나 같아질 때 까지 반복
      while (childIdx !== 0 && heap[parentIdx] < heap[childIdx]) {
        let [child, parent] = [heap[childIdx], heap[parentIdx]];
        // 자식과 부모 위치 바꾸기
        heap[childIdx] = parent;
        heap[parentIdx] = child;
        // 인덱스 변경
        childIdx = parentIdx;
        parentIdx = Math.floor((childIdx - 1) / 2);
      }
    }
  }
  /**
   * 1, 합이 비어 있으면 0 반환
   * 2. 힙 크기 1이면 pop 반환
   * 3. 루트를 반환 값으로 저장, 처음에 들어온 값을 루트로 저장하고 자식들과 계속 비교하며 내리기
   */
  popMax() {
    let heap = this.heap;

    if (heap.length === 0) return 0;
    if (heap.length === 1) return heap.pop();
    // 최대값 저장
    let max = heap[0];
    // 가장 처음 값 루트로 저장
    heap[0] = heap.pop();
    /**
     * 부모와 두 자식 비교 더 큰 자식 swap
     * 왼쪽, 오른쪽 자식 중 부모보다 큰 경우 반복
     */
    let parentIdx = 0;
    let leftChildIdx = parentIdx * 2 + 1;
    let rightChildIdx = parentIdx * 2 + 2;

    while (
      (heap[leftChildIdx] && heap[leftChildIdx] > heap[parentIdx]) ||
      (heap[rightChildIdx] && heap[rightChildIdx] > heap[parentIdx])
    ) {
      // 부모 값 저장
      let parent = heap[parentIdx];
      // 기본 값은 왼쪽으로 저장
      let child = heap[leftChildIdx];
      let childIdx = leftChildIdx;
      // 오른쪽 자식이 있고, 오른쪽이 왼쪽보다 크면 오른쪽으로 교체
      if (heap[rightChildIdx] && heap[rightChildIdx] > heap[leftChildIdx]) {
        child = heap[rightChildIdx];
        childIdx = rightChildIdx;
      }
      // 부모와 선택된 자식(자식 중 더 큰 값) 교체
      heap[parentIdx] = child;
      heap[childIdx] = parent;
      // 내려가서 반복
      parentIdx = childIdx;
      leftChildIdx = parentIdx * 2 + 1;
      rightChildIdx = parentIdx * 2 + 2;
    }
    // 최대값 반환
    return max;
  }
}

const solution = (input) => {
  let idx = 0;
  const maxHeap = new MaxHeap();
  const N = Number(input[idx++]);
  let result = "";
  for (let i = 0; i < N; i++) {
    let el = Number(input[idx++]);

    if (el == 0) result += maxHeap.popMax() + "\n";
    else maxHeap.push(el);
  }
  console.log(result);
};

solution(input);
