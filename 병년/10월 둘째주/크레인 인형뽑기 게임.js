function solution(board, moves) {
    var answer = 0;
    var bucket = []
    var bucket_size = bucket.length;
    var N = board.length;
    
    for (var m = 0; m < moves.length; m++) {
        // 크레인 움직임 구하기
        let move = moves[m]
        // 보드 순회
        for (var i = 0; i < N; i++) {
            // 인형의 위치(세로로 탐색)
           const doll = board[i][move - 1]
           
           // 인형이 있을 경우
           if (doll !== 0) {
               // 인형을 뽑고
               board[i][move - 1] = 0
               // 스택에 인형이 있으면
               if (bucket[bucket.length - 1] === doll) {
                   // 터뜨리기
                   bucket.pop()
                   // 결과 값 2개 추가(사라진 인형이 2개이므로)
                   answer += 2
               } else {
                   // 스택에 인형 넣기
                   bucket.push(doll);
               }
               break;
           }
        }
    }
    return answer;
    
}
