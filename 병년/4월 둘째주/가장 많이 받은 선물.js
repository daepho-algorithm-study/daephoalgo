function solution(friends, gifts) {
    var answer = Array.from({length: friends.length}, () => 0);
    const arr = Array.from({length: friends.length}, () => Array(friends).fill(0))
    
    const giftScore = Array.from({length: friends.length}, () => 0)
    
    gifts.forEach((value) => {
        const [give, take] = value.split(" ")
        let giveIdx = friends.indexOf(give)
        let takeIdx = friends.indexOf(take)
        giftScore[giveIdx]++
        giftScore[takeIdx]--
        
        arr[giveIdx][takeIdx]++
    })
    for (let i = 0; i < friends.length; i++) {
        for (let j = 1; j < friends.length; j++) {
            if (arr[i][j] > arr[j][i]) {
                answer[i]++
            } else if (arr[j][i] > arr[i][j]) {
                answer[j]++
            }else {
                if (giftScore[i] > giftScore[j]) {
                    answer[i]++
                } else if (giftScore[j] > giftScore[i]) {
                    answer[j]++
                }
            }
        }
    }
    return answer;
}