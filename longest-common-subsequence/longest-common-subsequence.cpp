class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        int sa = a.length(), sb = b.length();
        vector<vector<int>>dp(sa + 1, vector<int>(sb + 1, INT_MIN));
        for (int i = 0;i <= sa;++i)dp[i][0] = 0;
        for (int i = 0;i <= sb;++i)dp[0][i] = 0;
        for (int i = 1;i <= sa;++i) {
            for (int j = 1;j <= sb;++j) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp.back().back();
    }
};