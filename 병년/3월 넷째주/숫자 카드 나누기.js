function solution(arrayA, arrayB) {
  var answer = 0;
  let aGcd = 0;
  let bGcd = 0;
  
  const gcd = (a, b) => {
    while (b !== 0) {
      const temp = a % b;
      a = b;
      b = temp;
    }
    return a;
  };
  for (let i = 0; i < arrayA.length; i++) {
    aGcd = gcd(aGcd, arrayA[i]);
  }
  for (let i = 0; i < arrayB.length; i++) {
    bGcd = gcd(bGcd, arrayB[i]);
  }
  let a = 0;
  let b = 0;

  if (arrayA.every((value) => value % aGcd === 0) && arrayB.every((value) => value % aGcd !== 0)) a = aGcd;
  if (arrayB.every((value) => value % bGcd === 0) && arrayA.every((value) => value % bGcd !== 0)) b = bGcd;

  answer = Math.max(a, b);
  return answer;
}
