function solution(elements) {
  const n = elements.length;
  const set = new Set();

  function dfs(start, depth, sum, idx) {
    if (depth > n) return;

    set.add(sum);

    const next = (idx + 1) % n;
    dfs(start, depth + 1, sum + elements[next], next);
  }

  for (let i = 0; i < n; i++) {
    dfs(i, 1, elements[i], i);
  }

  return set.size;
}
