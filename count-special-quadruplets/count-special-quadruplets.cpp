typedef long long ll;
class Solution {
public:
    int countQuadruplets(vector<int>& v) {
        ll sz = v.size(),res = 0;
        for (ll i = 0;i < sz;++i) {
            for (ll j = i + 1;j < sz;++j) {
                for (ll k = j + 1;k < sz;++k) {
                    for (ll l = k + 1;l < sz;++l)
                        if (v[i] + v[j] + v[k] == v[l])
                            ++res;
                }
            }
        }
        return res;
    }
};