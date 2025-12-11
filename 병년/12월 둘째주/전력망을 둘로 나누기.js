const solution = (n, wires) => {
  var answer = Infinity;

  let tree = Array.from(Array(n + 1), () => []);

  wires.map((el) => {
    let [a, b] = el;

    tree[a].push(b);
    tree[b].push(a);
  });
  // 끊어줄 노드를 인자로 받는 bfs 함수
  const bfs = (a, b) => {
    let head = 0;
    let count = 0;
    let visited = Array.from({ length: wires.length }, () => false);
    visited[a] = true;
    let queue = [a];
    // BFS 시작
    while (queue.length > head) {
      let idx = queue[head++];
      // tree 탐색

      for (let value of tree[idx]) {
        // 간선이 끊어져 있기 때문에 갈 수 있는 노드가 b 가 아닌경우, 방문하지 않은 경우
        if (value !== b && visited[value] !== true) {
          // 방문 체크
          visited[value] = true;
          // 다음 노드 추가해서 탐색 계속 진행
          queue.push(value);
        }
      }
      // 정점 하나를 탐색 했으므로 count + 1
      count++;
      console.log(count);
    }
    return count;
  };

  wires.forEach((el) => {
    let [a, b] = el;
    answer = Math.min(answer, Math.abs(bfs(a, b) - bfs(b, a)));
  });

  return answer;
};
