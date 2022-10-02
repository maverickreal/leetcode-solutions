class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
unordered_set<ll> getFactors(ll n) {
    if (n < 0)
        return {};
    if (n == 0)
        return { 0 };
    unordered_set<ll> res { 1, n };
    for (ll i = 2;i * i <= n;i++) {
        if (n % i == 0) {
            res.insert(i);
            if ((n / i) != i)
                res.insert(n / i);
        }
    }
    return res;
}
    int commonFactors(int a, int b) {
        auto fa=getFactors(a);
        auto fb=getFactors(b);
        ll ans=0;
        for(ll it:fa){
            if(fb.find(it)!=fb.end()){
                ++ans;
            }
        }
        return ans;
    }
};