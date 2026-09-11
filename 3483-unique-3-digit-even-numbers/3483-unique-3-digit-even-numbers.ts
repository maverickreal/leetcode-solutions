function totalNumbers(arr: number[]): number {
    const freq = new Uint8Array(10);
    const sz = arr.length;
    let ans: number = 0;

    for (let i: number = 0; i < sz; ++i) {
        ++freq[arr[i]];
    }

    for (let i: number = 1; i < 10; ++i) {
        if (freq[i] === 0) {
            continue;
        }
        --freq[i];

        for (let j: number = 0; j < 10; ++j) {
            if (freq[j] === 0) {
                continue;
            }
            --freq[j];

            for (let k: number = 0; k < 10; k += 2) {
                ans += freq[k] === 0 ? 0 : 1;
            }
            ++freq[j];
        }
        ++freq[i];
    }

    return ans;
};