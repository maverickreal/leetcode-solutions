function uniformArray(nums: number[]): boolean {
    const mo = _.min(nums.filter(num => (num & 1) === 1));
    let ao: boolean = true;
    let ae: boolean = true;

    nums.forEach(num => {
        if ((num & 1) === 0) {
            ao &&= mo < num;
        } else {
            ae &&= mo < num;
        }
    });

    return ao || ae;
};