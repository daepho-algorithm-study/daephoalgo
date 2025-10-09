function solution(m, n, board) {
    var answer = 0;
    const dx = [-1, 1, 0, 0]
    const dy = [0, 0, -1, 1]
    let flag = true
    board = board.map(row => row.split(""));
    while(flag) {
        flag = false
        // 이번턴에 지워진 블록 체크
        let toRemove = Array.from({ length: m }, () => Array(n).fill(false));

        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n - 1; j++) {
                let str = board[i][j]
                if (str === '0') continue;
                if (board[i+1][j] === str && board[i][j+1] === str && board[i+1][j+1] === str) {
                        toRemove[i][j] = true;
                        toRemove[i+1][j] = true;
                        toRemove[i][j+1] = true;
                        toRemove[i+1][j+1] = true;
                        flag = true;
                }
            }
        }
        
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if(toRemove[i][j]) {
                    board[i][j] = '0'
                    answer++
                }
            }
        }
        if (flag) isBoom(board);
    }
    return answer;
}

// 배열의 0인 부분 즉 터진 부분 채우기
function isBoom (board) {
    const rows = board.length;
    const cols = board[0].length;

    for (let col = 0; col < cols; col++) {
    // 현재 열에서 0이 아닌 값들만 추출 (위에서부터 순서대로)
    const stack = [];
        for (let row = 0; row < rows; row++) {
          if (board[row][col] !== '0') {
            stack.push(board[row][col]);
          }
        }

        // 아래쪽부터 다시 채우기
        for (let row = rows - 1; row >= 0; row--) {
          board[row][col] = stack.pop() || '0';
        }
    }
}