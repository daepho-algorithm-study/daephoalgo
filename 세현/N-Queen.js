const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
  .map((e) => Number(e));
//.map((line) => line.split(" ").map(Number));

// console.log(input);

// N-Queen 문제
// 맨 위에서부터 퀸을 채우기 때문에 왼쪽 대각선 아래, 아래, 오른쪽 대각선 아래 3방향만 라인을 점유하고 있는지 검사하면 됨
// isPromisig (유망성 검증)을 위해 세로 배열, 왼쪽 아래 대각선 배열, 오른쪽 아래 대각선 배열 3개를 준비
// 이때, 배열 크기는 세로 배열은 N, 대각선 배열의 크기는 2N-1 이 됨(직접 그어보면 알게 됨)
// 이 세로, 대각선들을 각각 사용하고 있는지? 를 체크해주면 됨(사용하고 있으면 해당 위치는 충돌되니 놓을 수 없음)

function solution(N) {
  let answer = 0;

  // 세로: isCol, 왼쪽 아래 대각: isDiagLeft, 오른쪽 아래 대각: isDiagRight

  /* visited 배열 방식 (false는 라인을 점유하고 있지 않은 상태가 됨)
  const isCol = Array.from({length: N}, () => false); 
  const isDiagLeft = Array.from({length: 2*N-1}, () => false);
  const isDiagRight = Array.from({length: 2*N-1}, () => false);
  */

 
 //const dfs = (row) => {    // 배열 방식
 const dfs = (row, colMask, diagLeftMask, diagRightMask) => {  //비트마스킹 방식
    // 비트마스킹 방식
    // 비트마스킹 방식은 배열이 비트로 이루어져 있다고 생각하면 편함
    // 0000 0001 이라 가정하면 저 1에 해당되는 번호의 라인을 점유하고 있는 것 과 같음(뒤에서부터 1번째)
    // 각 Mask들은 해당 라인을 사용하고 있는지에 대한 정보를 저장하고 있는 변수임

    if (row === N) {
      return answer++;
    }
    /* vsitied 배열 방식
    for (let col = 0; col < N; col++) {
    // 현재 위치가 세로, 대각선들 안에 들어있는지 비교 
        if (!isCol[col] && !isDiagLeft[row+col] && !isDiagRight[row-col+N-1]) {
        // 만약 프리하다면
            isCol[col] = true;
            isDiagLeft[row+col] = true;
            isDiagRight[row-col+N-1] = true;
            //각 라인들을 점유하고 있다는 표시를 해주고
            // 다음 단계로 넘어감
            dfs(row+1);
            //그리고 다음 차례를 위해 다시 원상복구를 해줘야 함(중요!!!!)
            isCol[col] = false;
            isDiagLeft[row+col] = false;
            isDiagRight[row-col+N-1] = false;
        }
    }
    */

    // isDiagRight에서 왜 row-col+N-1 를 해주냐면
    // row-col이 음수가 될 수 있기 때문임 (0행 3열 등..)

    // 비트마스킹 방식
    // 각 마스크마다 0인 비트는 해당 줄을 안 쓰고 있는 중, 1인 부분은 쓰고 있는 중임
    for (let col = 0; col < N; col++) {
        // 각 열을 돌면서

        // 각 Mask와 현재 위치를 비교함
        // 예시로 colMask가 1011 이고 col이 2 이면
        // 1(0001)을 왼쪽으로 2번 shift 하므로 0100 이 됨
        // 따라서   1011
        //       & 0100
        // ------> 0000  0이므로 fasle, 해당 라인은 free하다(점유X) 가 됨
        // 1 << col은 col 번째 라인을 핀포인트로 잡는 거라 생각하면 됨  
        if (!(colMask & (1 << col)) &&
            !(diagLeftMask & (1 << (row+col))) &&
            !(diagRightMask & (1 << (row-col+N-1)))
        ) {
            
            // 만약 라인을 다 쓸 수 있으면 다음 단계로 넘어가는데
            dfs(row+1,
                // 현재 colMask(라인사용정보)에 새로 점유된 라인을 추가해주는데 이 로직을 인자에 넣으면 현재 값에는 반영이 안됨!!
                // 그래서 다음 차례를 위한 복구 코드가 필요 없음
                colMask | (1 << col),
                diagLeftMask | (1 << (row+col)),
                diagRightMask | (1 << (row-col+N-1))
            );
        }
    }
  };

  dfs(0, 0, 0, 0);

  return answer;
}

console.log(solution(input[0]));
