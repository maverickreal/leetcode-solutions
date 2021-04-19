class Solution {
public:
    int minSteps(int n) {
        if(n==1)
            return 0;
    vector<pair<int, int>>dp(n - 1);
    dp[0] = { 2,1 };
    for (int i = 1;i < n - 1;++i) {
        dp[i].first = INT_MAX;
        for (int j = i - 1;j > -1;--j) {
            if ((i - j) % dp[j].second == 0) {
                int tmp = dp[j].first + (i - j) / dp[j].second;
                if (tmp < dp[i].first) {
                    dp[i].first = tmp;
                    dp[i].second = dp[j].second;
                }
            }
            if ((i - j) % (j + 2) == 0) {
                int tmp = dp[j].first + 1 + (i - j) / (j + 2);
                if (tmp < dp[i].first) {
                    dp[i].first = tmp;
                    dp[i].second = j + 2;
                }
            }
        }
    }
    //for (auto& it : dp)
      //  cout << it.first << ' ' << it.second << '\n';
    return dp.back().first;
}
};