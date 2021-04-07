class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size(), res = 0;
        for (int i = 0;i < m;++i)
            res += v[i][0];
        for (int i = 1;i < n;++i)
            res += v[0][i];
        for (int i = 1;i < m;++i) {
            for (int j = 1;j < n;++j) {
                if (v[i][j]) {
                    v[i][j] = 1 + min(v[i - 1][j], min(v[i - 1][j - 1], v[i][j - 1]));
                    res += v[i][j];
                }
            }
        }
        return res;
    }
};