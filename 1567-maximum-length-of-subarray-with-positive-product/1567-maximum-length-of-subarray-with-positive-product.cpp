class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res = 0;
    pi func(vi(ll)& v, ll in = 0) {
        if (v[in] > 0 && !res)
            res = 1;
        if (in < sz - 1) {
            pi ans = func(v, in + 1);
            if (!v[in])
                return { 0,0 };
            if (v[in] > 0) {
                ++ans.first;
                if (ans.second)
                    ++ans.second;
                res = max(res, ans.first);
                return ans;
            }
            ll tmp = ans.first;
            if (ans.second)
                ans.first = 1 + ans.second;
            else
                ans.first = 0;
            ans.second = 1 + tmp;
            res = max(res, ans.first);
            return ans;
        }
        return { v[in] > 0, v[in] < 0 };
    }

    int getMaxLen(vector<int>& v) {
        sz = v.size();
        func(v);
        return res;
    }
};