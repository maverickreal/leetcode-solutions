function minimumDeletions(nums: number[]): number {
    let mnInd: number = 0;
    let mn: number = nums[0];
    let mxInd: number = 0;
    let mx: number = nums[0];
    const sz = nums.length;

    for (let i: number = 1; i < sz; ++i) {
        if (nums[i] > mx) {
            mxInd = i;
            mx = nums[i];
        }

        if (nums[i] < mn) {
            mnInd = i;
            mn = nums[i];
        }
    }

    if (mxInd < mnInd) {
        mxInd += mnInd;
        mnInd = mxInd - mnInd;
        mxInd -= mnInd;
    }

    return Math.min(
        mnInd + 1 + sz - mxInd,
        mxInd + 1,
        sz - mnInd
    );
};