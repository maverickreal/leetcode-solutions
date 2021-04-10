class Solution {
public:
    int numSubmat(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        vector<vector<int>>memo(m, vector<int>(n));
        for (int i = 0;i < m;++i) {
            int t = 0;
            for (int j = n - 1;j > -1;--j) {
                if (!v[i][j])
                    t = 0;
                else
                    ++t;
                memo[i][j] = t;
            }
        }
        int res = 0;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                int mn = INT_MAX;
                for (int k = i;k < m;++k) {
                    mn = min(mn, memo[k][j]);
                    res += mn;
                }
            }
        }
        return res;
    }
};