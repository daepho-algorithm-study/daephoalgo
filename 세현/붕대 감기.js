function solution(bandage, health, attacks) {
    const [t, x, y] = bandage;
    const max_health = health
    let idx = 0;
    let sequen = 0;
    const last = attacks.length - 1;
    for (let i = 1; i <= attacks[last][0]; i++) {
        if (i === attacks[idx][0]) {
            health -= attacks[idx++][1];
            sequen = 0;
            if (health <= 0) return -1
        } else {
            health += x;
            sequen += 1;
            if (sequen === t) {
                health += y;
                sequen = 0;
            }
            health = health < max_health ? health : max_health;
        }
    }
    return health;
}