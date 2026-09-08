function countCommas(n: number): number {
    let ans: number = 0;
    let len: number = 0;
    let _N: number = n;

    while (_N > 0) {
        ++len;
        _N = (_N / 10) | 0;
    }

    for (let i: number = 4; i < len; ++i) {
        ans += 9 * Math.pow(10, i - 1);
    }
    ans += len > 3 ? n - Math.pow(10, len - 1) + 1 : 0;

    return ans;
};