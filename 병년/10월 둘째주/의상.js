function solution(clothes) {
    var answer = 1;
    const map = new Map()
    
    clothes.forEach((value) => {
        const [name, type] = value
        
        if (!map.has(type)) {
            map.set(type, 1)
        }
        else {
            map.set(type, map.get(type)+1);
        }
    })
    
    
    for (const [key, value] of map) {
        answer *= (value + 1)
    }
    

    return answer - 1;
}