class Solution {
public:
    int countSubstrings(string& s) {
        int sz = s.length();
        vector<vector<bool>>dp(sz, vector<bool>(sz, true));
        int res = sz;
        for (int i = 1;i < sz;++i) {
            for (int r = 0, c = i;r < sz && c < sz;++r, ++c) {
                dp[r][c] = s[r] == s[c] && dp[r + 1][c - 1];
                res += dp[r][c];
            }
        }
        return res;
    }
};