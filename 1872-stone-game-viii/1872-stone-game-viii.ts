function stoneGameVIII(stones: number[]): number {
    const sz = stones.length;
    stones.forEach((_, i) => stones[i] += stones[i - 1] ?? 0);
    let ans: number = stones[sz - 1];

    for (let i: number = sz - 2; i > 0; --i) {
        ans = Math.max(ans, stones[i] - ans);
    }

    return ans;
};