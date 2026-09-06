let dp: Array<Int32Array>;
let szs: number;
let szt: number;

const func = (str: string, tar: string, i: number, j: number): number => {
    if (j === szt) {
        return 1;
    }

    if (i === szs) {
        return 0;
    }

    if (dp[i][j] !== -1) {
        return dp[i][j];
    }
    const dont = func(str, tar, i + 1, j);
    let take: number = 0;

    if (str[i] === tar[j]) {
        take = func(str, tar, i + 1, j + 1);
    }

    return dp[i][j] = dont + take;
};

function numDistinct(s: string, t: string): number {
    szt = t.length;
    szs = s.length;
    dp = Array.from({ length: szs }, () => new Int32Array(szt).fill(-1));

    return func(s, t, 0, 0);
};