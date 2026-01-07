const solution = (board) => {
  var answer = -1;
  let oCnt = 0;
  let xCnt = 0;

  let oWin = false;
  let xWin = false;
  // O, X 개수 세기
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (board[i][j] === "O") oCnt++;
      else if (board[i][j] === "X") xCnt++;
    }
  }

  const validate = (b, str) => {
    const lines = [
      // 가로
      b[0][0] + b[0][1] + b[0][2],
      b[1][0] + b[1][1] + b[1][2],
      b[2][0] + b[2][1] + b[2][2],
      // 세로
      b[0][0] + b[1][0] + b[2][0],
      b[0][1] + b[1][1] + b[2][1],
      b[0][2] + b[1][2] + b[2][2],
      // 대각선
      b[0][0] + b[1][1] + b[2][2],
      b[0][2] + b[1][1] + b[2][0],
    ];

    // str(o or x)를 3개 더한 게 지금 가로, 세로, 대각선에 존재할 경우
    return lines.includes(str + str + str);
  };

  // 둘 다 개수가 0일 경우(아직 돌을 넣지 않았을 경우 가능 하므로 바로 1 리턴)
  if (oCnt === 0 && xCnt === 0) return 1;

  // o 가 선공이므로 x의 개수가 더 많다면 0 리턴
  if (oCnt < xCnt) return 0;

  // 번갈아서 진행하기 때문에 o의 개수가 x의 개수에 1을 더한 것 보다 많으면 0 리턴
  if (oCnt > xCnt + 1) return 0

  // 세로, 가로 대각선 검사
  
  // o 가 이길 수 있는 경우 검증
  if (validate(board, 'O')) oWin = true

  // x 가 이길 수 있는 경우 검증
  if (validate(board, 'X')) xWin = true;

  // 둘 다 이긴 경우라면 0 리턴
  if (oWin && xWin) return 0;

  // o 가 이긴 경우에 o의 개수가 x의 개수에 1을 더한 것보다 많으면 0 리턴
  if (oWin && oCnt !== xCnt + 1) return 0

  // x 가 이긴 경우에 x의 개수와 o의 개수가 동일하지 않을 경우 0 리턴
  if (xWin && oCnt !== xCnt) return 0

  // 그 외의 모든 경우는 1 리턴
  return 1;
};
