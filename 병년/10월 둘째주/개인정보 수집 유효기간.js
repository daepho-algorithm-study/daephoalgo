function solution(today, terms, privacies) {
    let answer = []
    const obj = terms.reduce((acc, cur) => {
      const [key, value] = cur.split(" "); 
      acc[key] = Number(value);
      return acc;
    }, {});
    
    
    for (let i = 0; i < privacies.length; i++) {
        let [date, term] = privacies[i].split(" ")
        
        if (!calc(obj[term], date, today)) {
            answer.push(i+1)
        }
    }

    return answer;
}

// 날짜 계산 함수 정의
function calc(term, date, today) {
    let [year, month, day] = date.split(".").map(Number);

    let ndate = new Date(year, month - 1, day);

    ndate.setMonth(ndate.getMonth() + term);
    
    let [ty, tm, td] = today.split(".").map(Number);
    let todayDate = new Date(ty, tm - 1, td);


    return todayDate < ndate ? true : false
}