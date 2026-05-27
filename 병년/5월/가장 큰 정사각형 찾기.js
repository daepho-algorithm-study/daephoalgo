const solution = (board) => {
  // 현재 위치에서 구할 수 있는 정사각형의 변의 길이를 당믄 dp 설정
  const dp = Array.from({ length: board.length }, () =>
    Array(board[0].length).fill(0),
  );

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      if (board[i][j] === 1) {
        // dp[i][j] 는 결국 정사각형이 될 수 있는 변이 되어야 함 따라서 현재 위치에서 정사각형이 될 수 있는 경우를 찾아봄
        // 즉, 현재 위치의 왼쪽 대각선의 값, 왼쪽 옆의 값, 위의 값을 확인하면 정사각형이 될 지 안 될지를 확인할 수 있음
        // 또한 초기 값을 0으로 설정했기에 앞에서 고른 값 중에서 가장 작은 값에 +1을 더함
        // 그렇게 하면 정사각형이 될 수 있는 모든 후보 중에서 작은 값부터 채워갈 것임
        // 예를 들어 다음과 같이 board 가 주어지면,
        /**
         * [[0, 1, 1, 1],
         *  [1, 1, 1, 1],
         *  [1, 1, 1, 1],
         *  [0, 0, 1, 0]
         * ]
         */
        /**
         * dp 에는 다음과 같이 저장될 것이다.
         * [0, 1, 1, 1],
         * [1, 1, 2, 2],
         * [1, 2, 2, 3],
         * [0, 0, 1, 0]
         */
        // 그렇기에 결국 가장 최대값인 3을 뽑아서 제곱해주면 넓이를 구할 수 있게 된다.
        if (i === 0 || j === 0) {
          dp[i][j] = 1;
        } else {
          let mn = Math.min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
          dp[i][j] = mn + 1;
        }
      }
    }
  }
  let mx = 0;
  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[0].length; j++) {
      mx = Math.max(mx, dp[i][j]);
    }
  }
  return mx ** 2;
};
