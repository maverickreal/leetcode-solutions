class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9+7;
const char nl = '\n';

int minimumScore(const string&s, const string&t) {
    ll m=s.size(), n=t.size(), k=n-1;
    vi(ll)dp(n, -1);
    for(ll l=m-1;l>-1 && k>-1;--l){
        if(s[l]==t[k]){
            dp[k--]=l;
        }
    }
    if(k<0){
        return 0;
    }
    ll ans=k+1;
    for(ll i=0, j=0;i<m && j<n;++i){
        if(s[i]==t[j]){
            for(;k<n && dp[k]<=i;++k);
            ans=max(0LL, min(ans, k - (++j)));
        }
    }
    return ans;
}
};