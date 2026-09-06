let dp: Uint32Array;
let szs: number;
let szt: number;

const func = (str: string, tar: string): number => {
    dp[szt] = 1;
    let res: Uint32Array = new Uint32Array(szt + 1);

    for (let i: number = szs - 1; i > -1; --i) {
        for (let j: number = i; j > -1; --j) {
            res[j] = dp[j] ?? 0;

            if (str[i] === tar[j]) {
                res[j] += dp[j + 1] ?? 0;
            }
        }
        [dp, res] = [res, dp];
    }

    return dp[0];
};

function numDistinct(s: string, t: string): number {
    szt = t.length;
    szs = s.length;
    dp = new Uint32Array(szt + 1);

    return func(s, t);
};