class Solution {
public:
    int maxSumDivThree(vector<int>& v) {
        int sz = v.size();
        vector<vector<int>>dp(3, vector<int>(sz));
        dp[0][0] = v[0] % 3 == 0 ? v[0] : 0;
        dp[1][0] = v[0] % 3 == 1 ? v[0] : 0;
        dp[2][0] = v[0] % 3 == 2 ? v[0] : 0;
        for (int i = 1;i < sz;++i) {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1];
            dp[2][i] = dp[2][i - 1];
            if (v[i] % 3 == 0) {
                dp[0][i] += v[i];
                if (dp[1][i - 1])
                    dp[1][i] = max(dp[1][i], dp[1][i - 1] + v[i]);
                if (dp[2][i])
                    dp[2][i] += v[i];
            }
            else if (v[i] % 3 == 1) {
                dp[1][i] = max(dp[1][i], v[i] + dp[0][i - 1]);
                if (dp[2][i - 1])
                    dp[0][i] = max(dp[0][i], v[i] + dp[2][i - 1]);
                if (dp[1][i - 1])
                    dp[2][i] = max(dp[2][i], v[i] + dp[1][i - 1]);
            }
            else {
                if (dp[1][i - 1])
                    dp[0][i] = max(dp[0][i], v[i] + dp[1][i - 1]);
                if (dp[2][i - 1])
                    dp[1][i] = max(dp[1][i], v[i] + dp[2][i - 1]);
                dp[2][i] = max(dp[2][i], dp[0][i - 1] + v[i]);
            }
        }
        /*for (auto& it : dp) {
            for (auto& ti : it)
                cout << ti << ' ';
            cout << '\n';
        }*/
        return dp[0].back();
    }
};