class Solution {
public:
    bool stoneGame(vector<int>& v) {
        int sz = v.size();
        vector<vector<int>>dp(sz, vector<int>(sz)), dp2 = dp;
        for (int i = 0;i < sz;++i)
            dp[i][i] = dp2[i][i] = v[i];
        for (int i = 1;i < sz;++i) {
            for (int r = 0, c = i;r < sz && c < sz;++r, ++c) {
                dp[r][c] = v[c] - max(dp[r][c - 1], dp2[r][c - 1]);
                dp2[r][c] = v[r] - max(dp[r + 1][c], dp2[r + 1][c]);
            }
        }
        return dp[0].back() > -1 || dp2[0].back() > -1;
    }
};