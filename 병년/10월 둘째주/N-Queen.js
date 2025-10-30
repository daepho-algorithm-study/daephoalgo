function solution(n) {
    var answer = 0;
    // 1차원 배열로 행 저장 
    var arr = new Array(n).fill(-1)
    
    // 재귀를 통해 dfs 탐색
   const dfs = (col, arr) => {
        // 행 탐색을 마쳤을 경우 즉 모든 퀸을 놓을 수 있는 경우 값 추가
       if (col === n) {
           answer++
       }
       var temp = [...arr]
        
       for (var row = 0; row < n; row++) {
        // 현재 행에 열 위치 저장하기 위한 반복 및 재귀호출
            if (isValid(col, row, temp)) {
                temp[col] = row
                dfs(col + 1, [...temp])
            }
        }
     
     }
    // 가로, 대각선에 말이 존재하면 false 반환
    const isValid = (col, row, arr) => {
       for (var i = 0; i < col; i++) {
           // 이미 같은 열에 존재하면
           if (arr[i] === row) return false
           
           if(Math.abs(col - i) === Math.abs(row - arr[i])) return false;
       }
        return true
           
            // 대각선 상에 존재할 경우
    }
    dfs(0, arr)
    return answer;
}