class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    vi(bool)vis;
    bool func(const vi(int)& v, ll in) {
        if (vis[in]) {
            return false;
        }
        vis[in] = true;
        if (in < sz - 1 && v[in] == v[in + 1] && (in+2==sz || func(v, in + 2))) {
            return true;
        }
        if (in < sz - 2) {
            if (v[in] == v[in + 1] && v[in + 1] == v[in + 2] && (in+3==sz || func(v, in + 3))) {
                return true;
            }
            if (v[in] == v[in + 1] - 1 && v[in + 1] == v[in + 2] - 1 && (in+3==sz || func(v, in + 3))) {
                return true;
            }
        }
        return false;
    }
    bool validPartition(vector<int>& nums) {
        sz = nums.size();
        vis.resize(sz, false);
        return func(nums, 0);
    }
};