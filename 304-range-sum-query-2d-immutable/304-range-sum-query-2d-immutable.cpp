class NumMatrix {
    typedef int ll;
#define vi(x) vector<x>
public:
    vi(vi(ll))v;
    ll m, n;
    NumMatrix(vector<vector<int>>& V) {
        v = V;
        m = v.size(); n = v[0].size();
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                if (i)
                    v[i][j] += v[i - 1][j];
                if (j)
                    v[i][j] += v[i][j - 1];
                if (i && j)
                    v[i][j] -= v[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int x, int y, int a, int b) {
        ll res = v[a][b];
        if (y)
            res -= v[a][y - 1];
        if (x)
            res -= v[x - 1][b];
        if (x && y)
            res += v[x - 1][y - 1];
        return res;
    }
};