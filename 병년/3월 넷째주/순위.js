// function solution(n, results) {
//   var answer = 0;
//   const dist = Array.from({ length: n }, () => Array(n).fill(Infinity));
//   for (let i = 0; i < n; i++) {
//     dist[i][i] = 0;
//   }
//   for (let [a, b] of results) {
//     dist[a - 1][b - 1] = 1;
//   }

//   for (let k = 0; k < n; k++) {
//     for (let i = 0; i < n; i++) {
//       for (let j = 0; j < n; j++) {
//         dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
//       }
//     }
//   }
//   for (let i = 0; i < n; i++) {
//     count = 0;
//     for (let j = 0; j < n; j++) {
//       if (i === j) continue;
//       if (dist[i][j] !== Infinity || dist[j][i] !== Infinity) count++;
//     }
//     if (count === n - 1) answer++;
//   }
//   return answer;
// }


