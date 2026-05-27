function solution(today, terms, privacies) {
    // 연, 월, 일 로 나누기
    const [t_Y, t_M, t_D] = today.split('.').map(Number);
    // 약관 기관 맵
    const term_map = new Map();
    
    // 약관 유효기관 맵핑해놓기
    for (const term of terms) {
        const [alpa, num] = term.split(' ');
        term_map.set(alpa, Number(num));
    }
    
    const answer = [];
    
    // 개인정보 유효기간 확인
    for (let i = 0; i < privacies.length; i++) {
        // 유효기간, 약관 분리
        const [date, con] = privacies[i].split(' ');
        
        // 유효기간을 연 월 일로 분리
        const [p_Y, p_M, p_D] = date.split('.').map(Number);
        
        // 수집 일자와 현재 시간을 비교
        const diff_Y = t_Y - p_Y;
        
        const diff_M = diff_Y * 12 + t_M - p_M;
        
        const diff_D = diff_M * 28 + t_D - p_D;
        
        // 약관 기간보다 지났으면 결과에 추가
        if (term_map.get(con) * 28 <= diff_D) answer.push(i+1);    
    }
    
    return answer;
    
}