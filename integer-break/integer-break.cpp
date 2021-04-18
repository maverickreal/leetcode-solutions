class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n - 1);
        ++dp[0];
        for (int i = 1;i < n - 1;++i) {
            for (int j = i - 1;j > -1;--j)
                dp[i] = max(dp[i], (i - j) * max(dp[j], j + 2));
        }
        return dp.back();
    }
};