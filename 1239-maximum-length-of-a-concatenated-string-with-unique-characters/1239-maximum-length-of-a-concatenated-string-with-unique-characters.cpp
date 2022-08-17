class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res;
    void func(const vi(string)& v, ll in, ll mask) {
        if (in == sz) {
            ll ans = 0;
            while (mask > 0) {
                if (mask & 1) {
                    ++ans;
                }
                mask >>= 1;
            }
            res = max(res, ans);
            return;
        }
        func(v, in + 1, mask);
        ll curMask = mask;
        bool fl = true;
        for (char ch : v[in]) {
            if (curMask & (1 << (ch - 'a'))) {
                fl = false;
                break;
            }
            curMask |= (1 << (ch - 'a'));
        }
        if (fl) {
            func(v, in + 1, curMask);
        }
    }

    ll maxLength(const vi(string)& v) {
        sz = v.size();
        res = 0;
        func(v, 0, 0);
        return res;
    }
};