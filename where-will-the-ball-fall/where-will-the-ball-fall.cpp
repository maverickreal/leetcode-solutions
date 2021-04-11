class Solution {
public:
    vector<int> findBall(vector<vector<int>>& v) {
    int m = v.size(), n = v[0].size();
    vector<int>res(n);
    for (int i = 1;i < n;++i)
        res[i] = i;
    for (int i = 0;i < m;++i) {
        vector<int>tmp(n, -1);
        for (int j = 0;j < n;++j) {
            if (res[j] == -1)
                continue;
            if ((v[i][j] == -1 && j < 1) || (v[i][j] == 1 && j > n - 2))
                continue;
            if ((v[i][j] == 1 && v[i][j + 1] == -1) || (v[i][j] == -1 && v[i][j - 1] == 1))
                continue;
            tmp[j + v[i][j]] = res[j];
        }
        res = move(tmp);
    }
    vector<int>ans(n, -1);
    for (int i = 0;i < n;++i)
        if (res[i] > -1)
            ans[res[i]] = i;
    return ans;
}
};