class Solution {
public:
    int minimumDeleteSum(string& sa, string& sb) {
        int sza = sa.length(), szb = sb.length();
        vector<vector<int>>dp(sza + 1, vector<int>(szb + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1;i <= szb;++i)
            dp[0][i] = dp[0][i - 1] + sb[i - 1] - 'a' + 97;
        for (int i = 1;i <= sza;++i)
            dp[i][0] = dp[i - 1][0] + sa[i - 1] - 'a' + 97;
        for (int i = 1;i <= sza;++i) {
            for (int j = 1;j <= szb;++j) {
                if (sa[i - 1] == sb[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] = min(min(sa[i - 1] - 'a' + 97 + dp[i - 1][j], sb[j - 1] - 'a' + 97 + dp[i][j - 1]), dp[i][j]);
            }
        }
        return dp.back().back();
    }
};