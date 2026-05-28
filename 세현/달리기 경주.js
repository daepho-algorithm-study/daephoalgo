function solution(players, callings) {
    
    // 이름으로 랭크 찾기
    const rank_num = new Map();
    // 랭크로 이름 찾기
    const rank_str = new Map();
    
    // 2개 각각 키-값 형태로 저장 
    let idx = 0;
    for (const player of players) {
        rank_num.set(player, idx);
        rank_str.set(idx, player);
        idx++;
    }
    
    // 호명하는 순서대로 선수 찾아서 등업
    for (const over of callings) {
        // 추월한 선수 등수 찾기
        const num = rank_num.get(over);
        // 추월 당한 선수 이름 찾기
        const under = rank_str.get(num-1);
        
        // 이름-등수 맵 업데이트
        rank_num.set(over, num-1);
        rank_num.set(under, num);
        
        // 등수-이름 맵 업데이트
        rank_str.set(num-1, over);
        rank_str.set(num, under);
    }
    // 최종 결과에 등수 순서대로 이름 채워넣기
    const answer = Array.from({length: players.length}, (_, index) => rank_str.get(index));
    
    return answer;

} 