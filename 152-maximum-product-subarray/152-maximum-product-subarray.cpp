class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res = INT_MIN;
    pi func(vi(ll)& v, ll in) {
        res = max(res, v[in]);
        if (in < sz - 1) {
            pi p = func(v, in + 1), ret = { 0,0 };
            if (v[in] > -1) {
                res = max(res, v[in] * p.first);
                ret.first = max(1, v[in] * p.first);
                ret.second = p.second * v[in];
            }
            else {
                res = max(res, v[in] * p.second);
                ret.first = max(1, v[in] * p.second);
                ret.second = v[in];
                if(p.first>0)
                    ret.second*=p.first;
            }
            return ret;
        }
        pi ret;
        if (v[in] > -1) {
            ret.first = max(1, v[in]);
            ret.second = 0;
        }
        else {
            ret.first = 1;
            ret.second = v[in];
        }
        return ret;
    }
    int maxProduct(vector<int>& v) {
        sz = v.size();
        func(v, 0);
        return res;
    }
};