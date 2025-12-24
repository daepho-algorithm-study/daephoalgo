function solution(arr1, arr2) {
  const n = arr1.length;
  const m = arr2.length;
  const k = arr2[0].length;

  const result = Array.from({ length: n }, () => Array(k).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < k; j++) {
        for (let t = 0; t < m; t++) {
            result[i][j] += arr1[i][t] * arr2[t][j]
        }
    }
  }

  return result
}
