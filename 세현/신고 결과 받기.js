function solution(id_list, report, k) {
    let answer = Array.from({length: id_list.length}, () => 0);
    const report_who = {};
    const rep_status = {};
    let idx = 0;
    const label = {}
    for (const id of id_list) {
        rep_status[id] = new Set();
        label[id] = idx++;
    }
    
    for (const line of report) {
        const [ham, dangham] = line.split(' ');
        rep_status[dangham].add(ham);
    }
    for (const rep in rep_status) {
        if (rep_status[rep].size >= k) {
            for (const r of rep_status[rep]) {
                answer[label[r]]++;
            }
        }
    }
    
    return answer;
}