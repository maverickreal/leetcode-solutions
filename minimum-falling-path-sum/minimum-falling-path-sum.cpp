class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int sz = v.size();
        for (int i = 1;i < sz;++i) {
            for (int j = 1;j < sz - 1;++j)
                v[i][j] += min(min(v[i - 1][j - 1], v[i - 1][j]), v[i - 1][j + 1]);
            v[i][0] += min(v[i - 1][0], v[i - 1][1]);
            v[i][sz - 1] += min(v[i - 1][sz - 1], v[i - 1][sz - 2]);
        }
        return *min_element(v.back().begin(), v.back().end());
    }
};