class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res = 0;
    void func(vi(ll)& v, ll in, ll bs, ll ss, ll press) {
        //cout<<in<<' '<<bs<<' '<<ss<<' '<<press<<nl;
        res = max(res, ss);
        if (in > sz - 1)
            return;
        ll ps = press;
        press = ss;
        ss = max(ss, bs + v[in]);
        bs = max(bs, ps - v[in]);
        func(v, in + 1, bs, ss, press);
    }
    int maxProfit(vector<int>& v) {
        sz = v.size();
        func(v, 1, -v[0], 0, 0);
        return res;
    }
};