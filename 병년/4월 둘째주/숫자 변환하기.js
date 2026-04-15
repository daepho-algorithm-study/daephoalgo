const solution = (x, y, n) => {
  let answer = 0;
  const visited = Array(1000000).fill(false);
  const bfs = () => {
    let queue = [[x, 0]];
    let head = 0;

    while (queue.length > head) {
      let [cur, depth] = queue[head++];
      if (cur === y) return depth;
      const next = [cur + n, cur * 2, cur * 3];
      for (let i = 0; i < next.length; i++) {
        if (!visited[next[i]] && next[i] <= 1000000) {
          queue.push([next[i], depth + 1]);
          visited[next[i]] = true;
        }
      }
    }

    return -1;
  };

  answer = bfs();
  return answer;
};
