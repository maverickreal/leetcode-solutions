class Solution {
public:
    int sz;
    vector<vector<int>>dp;
    vector<int>* V;
    int func(int i = 0, int m = 1) {
        if (i >= sz) return 0;
        if (dp[i][m] != -1)
            return dp[i][m];
        int t = 0, ans = INT_MIN;
        for (int j = 0;j < m << 1;++j) {
            if (j < sz - i)
                t += V->at(i + j);
            ans = max(ans, t - func(i + j + 1, max(j + 1, m)));
        }
        dp[i][m] = ans;
        return ans;
    }
    int stoneGameII(vector<int>& v) {
        V = &v;
        sz = v.size();
        dp.resize(sz, vector<int>((sz << 1) + 1, -1));
        int sum = accumulate(v.begin(), v.end(), 0);
        return (sum + func()) >> 1;
    }
};