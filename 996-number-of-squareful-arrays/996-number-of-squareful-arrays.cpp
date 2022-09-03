class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    unordered_set<ll>ust;
    bool isps(const ll& n) {
        if (n < 4) {
            return (n < 2);
        }
        ll i = 1;
        for (;i * i < n;++i);
        return (i * i == n);
    }
    ll func(const vi(int)& v, ll bm, ll pre) {
        if (__builtin_popcount(bm) == sz) {
            return 1;
        }
        ll res = 0;
        for (ll i = 0;i < sz;++i) {
            if ((bm & (1 << i)) == 0 && (pre == -1 || ust.find(pre + v[i]) != ust.end()) && (i == 0 || v[i - 1] < v[i] || (bm & (1 << (i - 1))))) {
                res += func(v, bm | (1 << i), v[i]);
            }
        }
        return res;
    }
    int numSquarefulPerms(vector<int>& v) {
        sz = v.size();
        for (ll i = 0;i * i <= mod - 7;++i) {
            ust.insert(i * i);
        }
        sort(v.begin(), v.end());
        return func(v, 0, -1);
    }
};