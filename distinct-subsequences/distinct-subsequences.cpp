class Solution {
public:
    int numDistinct(string& s, string& t) {
        int szs = s.length(), szt = t.length();
        vector<vector<unsigned int>>dp(szt, vector<unsigned int>(szs));
        for (int i = 0;i < szs;++i) {
            if (i)
                dp[0][i] = dp[0][i - 1];
            if (t[0] == s[i])
                ++dp[0][i];
        }
        for (int i = 1;i < szt;++i) {
            for (int j = i;j < szs;++j) {
                dp[i][j] += dp[i][j - 1];
                if (t[i] == s[j])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp.back().back();
    }
};