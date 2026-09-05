function firstStableIndex(nums: number[], k: number): number {
    const sz = nums.length;
    const mn = Uint32Array.from(nums);

    for (let i: number = sz - 1; i > -1; --i) {
        mn[i] = (i === sz - 1 || mn[i] < mn[i + 1]) ? mn[i] : mn[i + 1];
    }

    for (let i: number = 0, mx: number = -1; i < sz; ++i) {
        mx = Math.max(mx, nums[i]);

        if ((mx - mn[i]) <= k) {
            return i;
        }
    }

    return -1;
};