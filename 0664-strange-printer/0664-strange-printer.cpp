class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp;
    ll func(const string&s, ll l, ll r){
        if(l>r){
            return 0;
        }
        ll&ans=dp[l][r];
        if(ans==-1){
            ans=func(s, l, r-1)+1;
            for(ll i=l;i<r;++i){
                if(s[i]==s[r]){
                    ans=min(ans, func(s, l, i-1)+func(s, i, r-1));
                }
            }
        }
        return ans;
    }
    int strangePrinter(const string&s) {
        n=s.size();
        dp.assign(n, vi(ll)(n, -1));
        return func(s, 0, n-1);   
    }
};