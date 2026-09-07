let sz: number;
const mod = 1e9 + 7;
let dp: Uint32Array;

const func = (str: string): number => {
    let res: Uint32Array = new Uint32Array(27);
    dp[0] = 0;

    for (let i: number = sz-1; i > -1; --i) {
        for (let j: number = 0; j < 27; ++j) {
            const curId = 1 + str.charCodeAt(i) - 'a'.charCodeAt(0);
            const dont = j === curId ? 0 : dp[j];
            const take = dp[curId];
            res[j] = (dont + take) % mod;
        }
        [dp, res] = [res, dp];
    }

    return dp[0];
};

function distinctSubseqII(s: string): number {
    sz = s.length;
    dp = new Uint32Array(27).fill(1);

    return func(s);
};