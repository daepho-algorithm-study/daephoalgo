const fs = require("fs");
const path = require("path");
const input = fs
  .readFileSync(
    process.platform === "linux"
      ? "/dev/stdin"
      : path.join(__dirname, "input.txt"),
  )
  .toString()
  .trim()
  .split(/\s+/);

const solution = (input) => {
  let idx = 0;

  const direction = [];

  for (let i = 0; i < 11; i++) {
    const plus = Array(11).fill(0);
    const minus = Array(11).fill(0);
    plus[i] = 1;
    minus[i] = -1;
    direction.push(plus, minus);
  }

  // 11차원 크기
  const [M, N, O, P, Q, R, S, T, U, V, W] = Array.from({ length: 11 }, () =>
    Number(input[idx++]),
  );

  let result = 1;
  let zero = 0;

  const box = Array.from({ length: W }, () =>
    Array.from({ length: V }, () =>
      Array.from({ length: U }, () =>
        Array.from({ length: T }, () =>
          Array.from({ length: S }, () =>
            Array.from({ length: R }, () =>
              Array.from({ length: Q }, () =>
                Array.from({ length: P }, () =>
                  Array.from({ length: O }, () =>
                    Array.from({ length: N }, () =>
                      Array.from({ length: M }, () => Number(input[idx++])),
                    ),
                  ),
                ),
              ),
            ),
          ),
        ),
      ),
    ),
  );

  const queue = [];
  for (let w = 0; w < W; w++) {
    for (let v = 0; v < V; v++) {
      for (let u = 0; u < U; u++) {
        for (let t = 0; t < T; t++) {
          for (let s = 0; s < S; s++) {
            for (let r = 0; r < R; r++) {
              for (let q = 0; q < Q; q++) {
                for (let p = 0; p < P; p++) {
                  for (let o = 0; o < O; o++) {
                    for (let n = 0; n < N; n++) {
                      for (let m = 0; m < M; m++) {
                        if (box[w][v][u][t][s][r][q][p][o][n][m] === 1)
                          queue.push([w, v, u, t, s, r, q, p, o, n, m]);
                        if (box[w][v][u][t][s][r][q][p][o][n][m] === 0) {
                          zero++;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  const bfs = () => {
    let head = 0;
    while (queue.length > head) {
      const [w, v, u, t, s, r, q, p, o, n, m] = queue[head++];

      for (const d of direction) {
        const nw = w + d[0];
        const nv = v + d[1];
        const nu = u + d[2];
        const nt = t + d[3];
        const ns = s + d[4];
        const nr = r + d[5];
        const nq = q + d[6];
        const np = p + d[7];
        const no = o + d[8];
        const nn = n + d[9];
        const nm = m + d[10];

        if (
          0 <= nw &&
          nw < W &&
          0 <= nv &&
          nv < V &&
          0 <= nu &&
          nu < U &&
          0 <= nt &&
          nt < T &&
          0 <= ns &&
          ns < S &&
          0 <= nr &&
          nr < R &&
          0 <= nq &&
          nq < Q &&
          0 <= no &&
          no < O &&
          0 <= np &&
          np < P &&
          0 <= nn &&
          nn < N &&
          0 <= nm &&
          nm < M
        ) {
          if (box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] === 0) {
            box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] =
              box[w][v][u][t][s][r][q][p][o][n][m] + 1;
            result = Math.max(
              result,
              box[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm],
            );

            zero--;
            queue.push([nw, nv, nu, nt, ns, nr, nq, np, no, nn, nm]);
          }
        }
      }
    }
  };
  bfs();

  if (zero > 0) console.log(-1);
  else console.log(result - 1);
};
solution(input);
