typedef long long ll;
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& v) {
        ll m = v.size(), n = v[0].size();
        vector<vector<int>>res;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                if (!v[i][j]) {
                    //cout << 0 << ' ';
                    continue;
                }
                /* if (!res.empty()) {
                    auto& it = res.back();
                    if (!(i<it.front() || j<it[1] || i>it[2] || j>it.back()))
                        continue;
                } */
                int k = i, minJ = INT_MAX;
                for (;k < m;++k) {
                    if (!v[k][j])
                        break;
                    int l = j;
                    for (;l < n && v[k][l];++l);
                    --l;
                    minJ = min(minJ, l);
                }
                --k;
                for (int r = i;r <= k;++r) {
                    for (int c = j;c <= minJ;++c)
                        --v[r][c];
                }
                res.push_back({ i,j,k,minJ });
                // for (auto i : v) {
                //     for (int j : i)
                //         cout << j << ' ';
                //     cout << '\n';
                // }
                //cout << v[i][j] << ' ';
            }
            //cout << '\n';
        }
        return res;
    }
};