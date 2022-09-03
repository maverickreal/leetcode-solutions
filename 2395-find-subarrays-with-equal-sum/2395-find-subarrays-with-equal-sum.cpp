class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool findSubarrays(vector<int>& v) {
        ll sz = v.size();
        unordered_map<ll, ll>ump;
        for (ll i = 0;i < sz - 1;++i) {
            ump[v[i] + v[i + 1]]++;
        }
        for (auto it : ump) {
            if (it.second > 1) {
                return true;
            }
        }
        return false;
    }
};