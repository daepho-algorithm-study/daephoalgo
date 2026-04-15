const solution = (fees, records) => {
    const calc = (hour) => {
        let [h,m] = hour.split(":").map(Number)
        
        return h*60 + m
    }
    
    const result = {}
  const [free, normal, addMinuate, addFee] = fees;
  const obj = {};
  records.forEach((value) => {
    const [start, car, tp] = value.split(" ");
    if (!obj[car]) {
        obj[car] = []
    }
    obj[car].push([start, tp]);
  });
    
    for (const rec in obj) {
        let total = 0
        if (obj[rec].length % 2 !== 0) {
            obj[rec].push(["23:59", "OUT"]);
        }
        
        for (let r of obj[rec]) {
            if (r[1] === "IN") {
                total -= calc(r[0])
            } else {
                total += calc(r[0])
            }
        } 
        let fee = normal;
        if (total > free) {
            fee += Math.ceil((total - free) / addMinuate) * addFee;
        }
        result[rec] = fee
    }
    console.log(result)
    return Object.keys(result)
        .sort()
        .map((car) => result[car]);
};
