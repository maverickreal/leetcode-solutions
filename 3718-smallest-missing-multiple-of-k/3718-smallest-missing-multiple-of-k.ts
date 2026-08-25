function missingMultiple(nums: number[], k: number): number {
    const arr = new Array<number>();

    nums.forEach(num => {
        if ((num % k) === 0) {
            arr.push(num / k);
        }
    });
    arr.sort((a, b) => a - b);

    if (arr[0] !== 1) {
        return k;
    }

    for (let i: number = 0; i < arr.length; ++i) {
        if (arr[i + 1] > (arr[i] + 1)) {
            return k * (arr[i] + 1);
        }
    }

    return (arr.at(-1) + 1) * k;
};