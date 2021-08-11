class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int sz = v.size();
        vector<vector<int>>dp(sz, vector<int>(sz));
        for (int i = 2;i < sz;++i) {
            for (int r = 0, c = i;r < sz && c < sz;++r, ++c) {
                dp[r][c] = INT_MAX;
                for (int j = r + 1;j < c;++j)
                    dp[r][c] = min(dp[r][c], v[r] * v[c] * v[j] + dp[r][j] + dp[j][c]);
            }
        }
        return dp[0][sz - 1];
    }
};