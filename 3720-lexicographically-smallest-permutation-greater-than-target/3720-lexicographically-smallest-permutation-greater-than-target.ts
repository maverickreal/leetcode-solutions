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
    Object.freeze(freqCpy);
    let pos: number = -1;

    for (let i: number = 0; i < sz; ++i) {
        const nxt = getSmallestBigger(freq, tar[i]).length;

        if (nxt === 1) {
            pos = i;
        }

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

        if (--freq[tar[i]] === 0) {
            delete freq[tar[i]];
        }
    }
    chars[pos] = getSmallestBigger(freq, tar[pos]);

    if (--freq[chars[pos]] === 0) {
        delete freq[chars[pos]];
    }

    const remChars = Object.entries(freq)
        .sort((a, b) => (a[0] < b[0]) ? -1 : 1);

    for (let i: number = pos + 1, j: number = 0; i < sz; ++i) {
        chars[i] = remChars[j][0];
        j += (--remChars[j][1] === 0) ? 1 : 0;
    }

    return chars.join('');
};