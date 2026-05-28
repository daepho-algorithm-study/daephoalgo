function solution(schedules, timelogs, startday) {
    let answer = 0;
    
    // 출근 인정 시각을 계산하는 메소드
    const standardize = (num) => {
        let h = ~~(num / 100);
        let m = num % 100;
        
        m += 10;
        
        if (m >= 60) {
            m -= 60;
            h += 1;
        }
        
        return h*100 + m;
    }
    
    for (let i = 0; i < schedules.length; i++) {
        // 시작 요일에서 1 뺌(1 ~ 7 이 아닌 0 ~ 6 쓸 것임)    
        let today = startday - 1;
        
        // 출근 인정 시각 계산
        const limit = standardize(schedules[i]);
        // 개근 여부
        let gaeggeun = true;
        
        // 출근 시각 체크하기
        for (const timelog of timelogs[i]) {
            
            // 평일이면서(0 ~ 4) 인정 시각 지났으면 개근 취소
            if (today < 5 && timelog > limit) {
                gaeggeun = false;
                break;
            }
            // 요일 갱신
            today = (today + 1) % 7;

        }
        
        if (gaeggeun) answer += 1;
    }
    
    return answer;
}