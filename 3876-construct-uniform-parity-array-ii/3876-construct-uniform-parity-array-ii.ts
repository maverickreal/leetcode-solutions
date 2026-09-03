function uniformArray(nums: number[]): boolean {
    let mo: number = Infinity;
    const sz = nums.length;

    for (let i: number = 0; i < sz; ++i) {
        if ((nums[i] & 1) === 1 && nums[i] < mo) {
            mo = nums[i];
        }
    }
    let ao: boolean = true;
    let ae: boolean = true;

    for (let i: number = 0; i < sz && (ae || ao); ++i) {
        const found = mo < nums[i];

        if ((nums[i] & 1) === 0) {
            ao &&= found;
        } else {
            ae &&= found;
        }
    }

    return ao || ae;
};