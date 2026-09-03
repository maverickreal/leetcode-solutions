function uniformArray(nums: number[]): boolean {
    let minOdd: number = Infinity;
    const sz = nums.length;

    for (let i: number = 0; i < sz; ++i) {
        if ((nums[i] & 1) === 1 && nums[i] < minOdd) {
            minOdd = nums[i];
        }
    }
    let oddValid: boolean = true;
    let evenValid: boolean = true;

    for (
        let i: number = 0;
        i < sz && (evenValid || oddValid);
        ++i
    ) {
        const found = minOdd < nums[i];

        if ((nums[i] & 1) === 0) {
            oddValid &&= found;
        } else {
            evenValid &&= found;
        }
    }

    return evenValid || oddValid;
};