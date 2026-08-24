function sumGame(num: string): boolean {
    let bal: number = 0;
    const sz = num.length;

    for (let i: number = 0; i < sz; ++i) {
        const sign = (i < (sz >> 1)) ? 1 : -1;
        const code = num.charCodeAt(i) - '0'.charCodeAt(0);
        const val = (num[i] === '?') ? 4.5 : code;
        bal += sign * val;
    }

    return bal !== 0;
};