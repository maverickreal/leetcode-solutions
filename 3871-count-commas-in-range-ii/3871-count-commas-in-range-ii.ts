function countCommas(n: number): number {
    let ans: number = 0;
    let len: number = 0;
    let _N: number = n;

    while (_N > 0) {
        ++len;
        _N = Math.floor(_N / 10);
    }

    for (let i: number = 4; i <= len; ++i) {
        const cntPerWidth = ((i - 1) / 3) | 0;
        const pow = Math.pow(10, i - 1);
        const cnt = (i === len) ? (n - pow + 1) : (9 * pow);
        ans += cnt * cntPerWidth;
    }

    return ans;
};