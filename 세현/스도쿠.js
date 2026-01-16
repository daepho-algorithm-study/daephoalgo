const fs = require("fs");

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .trim()
  .split(/\r?\n/)
//   .map((e) => Number(e));
.map((line) => line.split(" ").map(Number));

// console.log(input);

function solution(sudoku) {
  // Int32Array(9) :  Array(9).fill(0) 과 비슷한 배열이지만 메모리 구조가 살짝 다름
  // js에서 배열은 객체인데 Int32Array를 통해 특수한 형태의 (무조건 int 0으로 채워지는) 객체를 만든 것임
  // 그냥 배열로 만들면 메모리 상 요소들이 여기저기 띄워져 있는데 int32Array는 딱 붙어있어서 연산 속도가 미미하게 빨라짐
  // 범위가 작아서 [0, 0, 0, 0, 0, 0, 0, 0, 0] 으로 선언해도 큰 차이는 없음
  const rowMasks = new Int32Array(9);
  const colMasks = new Int32Array(9);
  const boxMasks = new Int32Array(9);

  // 각 마스크들은 0으로 채워져 있음 (마스크는 1부터 9까지 사용된 수들을 비트로 표현한 것임.
  // 예시로 마스크가 1110111000 이면 맨 오른쪽부터 0에 해당되고 1, 2, 6이 사용 안된 것들임. (0 자리는 무시))
  // rowMask -> 0~8번 행의 마스크들, colMask -> 0~8번 열의 마스크들
  // boxMasks -> 0~8번 박스의 마스크들이며 0번은 ([012], [012]), 1번은 ([012], [345])... 이런 식으로 이루어저 있음

  const blankList = []; // 비어저 있는 칸들 리스트

  for(let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {

        // 스도쿠 순회하면서 비어져있는(0인) 칸들을 빈칸 리스트에 넣어줌
        if (sudoku[i][j] === 0) {
            blankList.push([i, j]);

        } else {    // 빈 칸이 아니라면 해당되는 마스크에다가 해당하는 숫자 자리에 표시를 해줌
            
            // 예시로 rowMasks[0] (0번째 줄)이 0000000000 이고 해당 칸이 4 이면
            // 1 << 4, 즉 10000 이랑 위 마스크를 OR 연산하면
            // 0000010000 이 되므로 4를 사용했다는 표시를 해줄 수 있음
            rowMasks[i] |= (1 << sudoku[i][j]);
            colMasks[j] |= (1 << sudoku[i][j]);

            // 몇번째 box인지를 검사하려면 해당 좌표의 (행 // 3) x 3 + (열 // 3)을 해주면 됨 (//는 몫연산)
            // 예시로 (4행 6열) 좌표는 5번째 박스에 들어가 있는데 4//3 x 3 = 1 x 3 = 3 이고 6//2 = 2 이므로 3 + 2 = 5 로 맞아떨어짐
            const boxIndex = Math.floor(i/3)*3 + Math.floor(j/3);
            boxMasks[boxIndex] |= (1 << sudoku[i][j]);

        }
    }
  }
  
  // 검증 및 숫자 채워 넣는 함수. 비어있는 칸들을 순회하면서 가능한 숫자를 채워넣음
  const numbering = (blankIdx) => {

    // 빈칸 리스트를 모두 돌았으면 true를 반환하고(성공적으로 끝났음을 알리고) 종료
    if (blankList.length === blankIdx) return true;

    // 현재 빈칸의 좌표
    const [curRow, curCol] = blankList[blankIdx];

    // 박스 인덱스 계산
    const bIdx = Math.floor(curRow / 3) * 3 + Math.floor(curCol / 3);

    // 해당되는 행, 열 박스에서 어떤 수들을 사용했는지 나타내주는 마스크
    // 행과 열, 박스의 마스크들을 모두 OR 연산하면 아직 사용되지 않은 숫자들이 0으로 찍힌 비트가 튀어나옴 (1110111110 이면 6이 됨)
    const ableMask = rowMasks[curRow] | colMasks[curCol] | boxMasks[bIdx];

    // 비트 안에서 어떤 수들이 사용 가능한지는 1부터 9까지 반복문 돌리면서 찾아줘야 함
    for (let curNum = 1; curNum <= 9; curNum++) {

        const candidate = 1 << curNum
        //해당 수를 비트로 바꿔줌 (6이면 1000000 이 됨)

        if (!(ableMask & candidate)) { // 만약 사용 가능한 수면
          
          //해당 수를 사용했다는 표시를 해줌(해당 자리를 1로 올림)
          rowMasks[curRow] |= candidate;
          colMasks[curCol] |= candidate;
          boxMasks[bIdx] |= candidate;
          // 스도쿠 빈칸도 채워 줌
          sudoku[curRow][curCol] = curNum;

          //만약 이 다음 단계가 통과되면 true를 반환하면서 종료하고
          if (numbering(blankIdx+1)) return true;
          
          // 통과되지 못했다면 다시 이전 단계로 롤백해 줘야 함
          rowMasks[curRow] &= ~candidate;
          colMasks[curCol] &= ~candidate;
          boxMasks[bIdx] &= ~candidate;
          sudoku[curRow][curCol] = 0;
        }
    }
    return false;
  }

  numbering(0);

  return sudoku.map((line) => line.join(" ")).join('\n');
}

console.log(solution(input));
