class Solution {
public:
    int n;
    vector<vector<bool>>vis;
    vector<vector<int>>acc;

    int func(int i, int j, vector<vector<int>>& v) {
        if (i < 0 || j < 0 || i == n || j == n || !v[i][j] || vis[i][j])
            return 0;
        vis[i][j] = true;
        return func(i + 1, j, v) + func(i - 1, j, v) + func(i, j + 1, v) + func(i, j - 1, v) + 1;
    }
    void fill(int i, int j, int col, int val, vector<vector<int>>& v) {
        if (i < 0 || j < 0 || i == n || j == n || acc[i][j] == col || !v[i][j])
            return;
        acc[i][j] = col;
        v[i][j] = val;
        fill(i + 1, j, col, val, v);
        fill(i - 1, j, col, val, v);
        fill(i, j + 1, col, val, v);
        fill(i, j - 1, col, val, v);
    }
    int largestIsland(vector<vector<int>>& v) {
        n = v.size();
        vis.resize(n, vector<bool>(n));
        acc.resize(n, vector<int>(n));
        for (int i = 0, col = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                if (v[i][j] == 1 && !vis[i][j])
                    fill(i, j, ++col, func(i, j, v), v);
            }
        }
        int res = 0;
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                res = max(res, v[i][j]);
                if (!v[i][j]) {
                    int tmp = 0;
                    if (i)
                        tmp += v[i - 1][j];
                    if (i < n - 1 && (!i || acc[i + 1][j] != acc[i - 1][j]))
                        tmp += v[i + 1][j];
                    if (j && (!i || acc[i][j - 1] != acc[i - 1][j]) && (i + 1 >= n || acc[i + 1][j] != acc[i][j - 1]))
                        tmp += v[i][j - 1];
                    if (j < n - 1 && (!i || acc[i - 1][j] != acc[i][j + 1]) && (i + 1 >= n || acc[i + 1][j] != acc[i][j + 1]) && (!j || acc[i][j - 1] != acc[i][j + 1]))
                        tmp += v[i][j + 1];
                    res = max(res, tmp + 1);
                }
            }
        }
        /* for (auto& it : v) {
            for (int& j : it)
                cout << j << ' ';
            cout << '\n';
        }
        for (auto& it : acc) {
            for (int& j : it)
                cout << j << ' ';
            cout << '\n';
        } */
        return res;
    }
};
