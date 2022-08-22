class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int maxNumberOfFamilies(int m, vector<vector<int>>& v) {
        ll n = 10, res = m * 2;
        unordered_map<ll, ll>ump;
        for (const auto& it : v) {
            ump[it[0] - 1] |= 1 << (it[1] - 1);
        }
        for (auto it : ump) {
            ll bm = it.second, j = 1, ans = 0;
            res -= 2;
            for (;j < 5 && (bm & (1 << j)) == 0;++j);
            if (j == 5) {
                ++ans;
                for (;j < 9 && (bm & (1 << j)) == 0;++j);
                if (j == 9) {
                    ++ans;
                }
            }
            else {
                for (j = 3;j < 7 && (bm & (1 << j)) == 0;++j);
                if (j == 7) {
                    ++ans;
                }
                else if (j < 5) {
                    for (j = 5;j < 9 && (bm & (1 << j)) == 0;++j);
                    if (j == 9) {
                        ++ans;
                    }
                }
            }
            res += ans;
        }
        return res;
    }
};