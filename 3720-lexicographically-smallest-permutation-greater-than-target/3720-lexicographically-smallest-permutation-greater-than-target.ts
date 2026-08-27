const getSmallestBigger = (freq: Record<string, number>, ch: string): string => {
    let ans: string = "";

    for (const key in freq) {
        const better = key > ch && freq[key] > 0 &&
            (ans === "" || key < ans);

        if (better) {
            ans = key;
        }
    }

    return ans;
};

function lexGreaterPermutation(str: string, tar: string): string {
    let freq: { [_: string]: number } = {};
    const sz = str.length;

    for (const ch of str) {
        freq[ch] = 1 + (freq[ch] ?? 0);
    }
    const freqCpy = { ...freq };
    let pos: number = -1;

    for (let i: number = 0; i < sz; ++i) {
        const nxt = getSmallestBigger(freq, tar[i]);
        pos = (nxt === "") ? pos : i;

        if (!freq[tar[i]]) {
            break;
        }
        --freq[tar[i]];
    }

    if (pos === -1) {
        return "";
    }
    const chars = new Array<string>(sz);
    freq = { ...freqCpy };

    for (let i: number = 0; i < pos; ++i) {
        chars[i] = tar[i];
        --freq[tar[i]];
    }
    chars[pos] = getSmallestBigger(freq, tar[pos]);
    --freq[chars[pos]];

    for (let i: number = 0; i < 26; ++i) {
        const ch = String.fromCharCode('a'.charCodeAt(0) + i);

        while (freq[ch]--) {
            chars[++pos] = ch;
        }
    }

    return chars.join('');
};
