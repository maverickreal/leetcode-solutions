class Solution {
public:
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

int peopleAwareOfSecret(int n, int d, int f) {
    vi(ll)dp(n);
    ++dp[0];
    for (ll i = 1;i < n;++i) {
        for (ll j = i - d;j > max(-1LL, i - f);--j)
            dp[i] = (dp[i] + dp[j]) % mod;
    }
    // for(ll d:dp)
    //     cout<<d<<' ';
    ll res=0;
    for(ll i=n-1;i>-1;--i){
        if(i+f>n-1)
            res=(res+dp[i])%mod;
        else
            break;
    }
    return res;
}
};