let dp: Array<Uint32Array>;
let szs: number;
let szt: number;

const func = (str: string, tar: string, i: number, j: number): number => {
    dp[szs][szt] = 1;

    for (let i: number = szs - 1; i > -1; --i) {
        for (let j: number = i; j > -1; --j) {
            dp[i][j] = dp[i + 1]?.[j] ?? 0;

            if (str[i] === tar[j]) {
                dp[i][j] += dp[i + 1]?.[j + 1] ?? 0;
            }
        }
    }

    return dp[0][0];
};

function numDistinct(s: string, t: string): number {
    szt = t.length;
    szs = s.length;
    dp = Array.from({ length: szs + 1 }, () => new Uint32Array(szt + 1).fill(0));

    return func(s, t, 0, 0);
};