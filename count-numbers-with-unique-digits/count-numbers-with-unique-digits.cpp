class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //if (!n) return 1;
        vector<pair<int, int>>dp(n + 1);
        dp[0] = { 0,1 };
        int res = 1;
        for (int i = 1;i <= n;++i) {
            dp[i].first = (dp[i - 1].first * 10) + (dp[i - 1].second * (i - 1));
            dp[i].second = pow(10, i) - pow(10, i - 1) - dp[i].first;
            res += dp[i].second;
        }
        return res;
    }
};