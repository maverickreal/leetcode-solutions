class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res;
    unordered_map<ll, ll>ump, umpskip;
    ll func(const vi(int)& v, ll in, bool skip) {
        if (in == sz) {
            return 0;
        }
        ll ans = 0;
        if (skip) {
            if (umpskip.find(in) == umpskip.end()) {
                ans = max(0LL, func(v, in + 1, false));
                ans = max(ans, v[in] + max(0LL, func(v, in + 1, true)));
                umpskip[in] = ans;
            }
            else{
                ans=umpskip[in];
            }
        }
        else {
            if (ump.find(in) == ump.end()) {
                ans = v[in]+max(0LL, func(v, in + 1, false));
                ump[in] = ans;
            }
            else{
                ans=ump[in];
            }
        }
        res = max(res, ans);
        //cout<<in<<' '<<skip<<' '<<ans<<nl;
        return ans;
    }
    int maximumSum(vector<int>& v) {
        sz = v.size(), res = LLONG_MIN;
        ll mx = *max_element(v.begin(), v.end());
        if (mx < 1) {
            return mx;
        }
        func(v, 0, true);
        return res;
    }
};