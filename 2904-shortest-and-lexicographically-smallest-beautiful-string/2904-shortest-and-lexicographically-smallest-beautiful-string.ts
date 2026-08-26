function shortestBeautifulSubstring(s: string, k: number): string {
    const sz = s.length;
    let ans: string = "";

    for (
        let i: number = 0, j: number = 0, cnt: number = 0;
        j < sz;
        ++j
    ) {
        cnt += (s[j] === '1') ? 1 : 0;

        while (cnt > k || s[i] === '0') {
            cnt -= (s[i++] === '1') ? 1 : 0;
        }
        const len = j - i + 1;
        const subStr = s.slice(i, j + 1);
        const betterRes = cnt === k && (ans.length === 0 ||
            len < ans.length || (ans.length === len &&
                subStr < ans));

        if (betterRes) {
            ans = subStr;
        }
    }

    return ans;
};