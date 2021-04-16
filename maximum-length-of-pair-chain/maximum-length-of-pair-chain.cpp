class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        int sz = v.size();
        vector<int>dp(sz, 1);
        sort(v.begin(), v.end());
        for (int i = 1;i < sz;++i) {
            for (int j = 0;j < i;++j)
                if (v[j][1] < v[i][0] && dp[j] >= dp[i])
                    dp[i] = dp[j] + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};