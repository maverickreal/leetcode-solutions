class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int equalPairs(vector<vector<int>>& v) {
        ll n = v.size();
        unordered_map<string, ll>rows, cols;
        for (ll i = 0;i < n;++i) {
            string row;
            for (ll j : v[i]) {
                row.append(to_string(j) + ",");
            }
            rows[row]++;
            string col;
            for (ll j = 0;j < n;++j) {
                col.append(to_string(v[j][i]) + ",");
            }
            cols[col]++;
        }
        ll ans = 0;
        for (auto it : rows) {
            ans += it.second * cols[it.first];
        }
        return ans;
    }
};