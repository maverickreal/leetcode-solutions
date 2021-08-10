class Solution {
public:
    int minCut(string& s) {
        int sz = s.length();
        vector<vector<bool>>dp(sz, vector<bool>(sz));
        vector<int>dp2(sz);
        for (int i = 0;i < sz;++i) {
            for (int r = 0, c = i;r < sz && c < sz;++r, ++c)
                if (s[r] == s[c] && (c - r < 2 || dp[r + 1][c - 1]))
                    dp[r][c] = true;
        }
        for (int i = 1;i < sz;++i) {
            if (dp[0][i])
                continue;
            dp2[i] = i;
            for (int j = i - 1;j > -1;--j)
                if (dp[j + 1][i] && dp2[j] < dp2[i])
                    dp2[i] = dp2[j] + 1;
        }
        return dp2.back();
    }
};