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

    while (
      (heap[leftChildIdx] && heap[leftChildIdx] < heap[parentIdx]) ||
      (heap[rightChildIdx] && heap[rightChildIdx] < heap[parentIdx])
    ) {
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
  // 입력 값 파싱
  const [N, M] = input[0].split(" ").map(Number);
  // A > B 라는 의미는 결국 방향을 가진 그래프를 의미하기 때문에 그래프 만들기
  const graph = Array.from({ length: N + 1 }, () => []);
  /**
   * 위상 정렬의 핵심인 진입 차수를 알기 위한 리스트로
   * 위상 정렬은 진입차수가 0인 경우의 정점을 큐에 넣고 원소와 연결된 간선의
   * 진입 차수를 줄여주고 큐(BFS) 탐색을 통해 진입차수가 0인 정점을 결과에 넣어준다
   * 특이한 점은 정렬의 결과가 여러가지 존재할 수 있다.
   */
  const arr = Array(N + 1).fill(0);
  const queue = new MinHeap();
  for (let i = 1; i <= M; i++) {
    const [A, B] = input[i].split(" ").map(Number);
    graph[A].push(B);
    arr[B]++;
  }
  // 해당 정점의 진입차수가 0이라면 큐에 넣기
  for (let i = 1; i <= N; i++) {
    if (arr[i] === 0) {
      queue.push(i);
    }
  }
  // 결과를 반환할 배열
  const result = [];
  // BFS 탐색
  const bfs = () => {
    while (queue.heap.length > 0) {
      // 진입차수가 0인 경우에만 큐에 저장되기 때문에 바로 결과 배열에 저장
      const next = queue.popMin();
      result.push(next);
      // 그래프를 순회
      for (const adj of graph[next]) {
        // 인접 정점의 진입차수 줄여주기
        arr[adj]--;
        // 만약 진입차수가 0이라면 다음 탐색 및 결과에 저장하기 위해 queue에 저장
        if (arr[adj] === 0) {
          queue.push(adj);
        }
      }
    }
  };

  bfs();
  console.log(result.join(" "));
};

solution(input);
