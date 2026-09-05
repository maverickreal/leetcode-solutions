function firstStableIndex(nums: number[], k: number): number {
    const sz = nums.length;
    const mx = BigInt64Array.from(nums, BigInt);
    const mn = BigInt64Array.from(nums, BigInt);

    for (let i: number = 0; i < sz; ++i) {
        mx[i] = (i === 0 || mx[i] > mx[i - 1]) ? mx[i] : mx[i - 1];
        mn[sz - i - 1] = (i === 0 || mn[sz - i - 1] < mn[sz - i]) ?
            mn[sz - i - 1] : mn[sz - i];
    }

    for (let i: number = 0; i < sz; ++i) {
        if ((mx[i] - mn[i]) <= k) {
            return i;
        }
    }

    return -1;
};