class Solution {
public:
    class dir {
    public:
        int u, d, l, r;
        dir() {
            d = l = r = u = 0;
        }
        dir(int U, int D, int L, int R) {
            u = U, d = D, l = L, r = R;
        }
    };
    int orderOfLargestPlusSign(int n, vector<vector<int>>& V) {
        int& sz = n;
        vector<vector<int>>mat(sz, vector<int>(sz, 1));
        for (auto& it : V)
            mat[it[0]][it[1]] = 0;
        vector<vector<dir>>v(sz, vector<dir>(sz));
        for (int i = 0;i < sz;++i) {
            for (int j = 0;j < sz;++j) {
                if (mat[i][j]) {
                    v[i][j].l = 1;
                    if (j)
                        v[i][j].l += v[i][j - 1].l;
                }
                if (mat[i][sz - j - 1]) {
                    v[i][sz - j - 1].r = 1;
                    if (j)
                        v[i][sz - j - 1].r += v[i][sz - j].r;
                }
                if (mat[j][i]) {
                    v[j][i].u = 1;
                    if (j)
                        v[j][i].u += v[j - 1][i].u;
                }
                if (mat[sz - j - 1][i]) {
                    v[sz - j - 1][i].d = 1;
                    if (j)
                        v[sz - j - 1][i].d += v[sz - j][i].d;
                }
            }
        }
        /* for (int j = 0;j < sz;++j) {
            for (int i = 0;i < sz;++i) {
                if (mat[i][j]) {
                    v[i][j].u = 1;
                    if (i)
                        v[i][j].u += v[i - 1][j].u;
                }
                if (mat[sz - i - 1][j]) {
                    v[sz - i - 1][j].d = 1;
                    if (i)
                        v[sz - i - 1][j].d += v[sz - i][j].d;
                }
            }
        } */
        int res = 0;
        for (int i = 0;i <= sz - 1;++i) {
            for (int j = 0;j <= sz - 1;++j)
                res = max(res, min(v[i][j].u, min(v[i][j].d, min(v[i][j].l, v[i][j].r))));
        }
        // for (auto it : v) {
        //     for (auto ti : it)
        //         cout << ti.u << ' ' << ti.d << ' ' << ti.l << ' ' << ti.r << "    ";
        //     cout << '\n';
        // }
        return res;
    }
};