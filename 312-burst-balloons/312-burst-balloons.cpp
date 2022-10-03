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
    ll func(vi(int)&v, ll l, ll r){
        if(l>r){
            return 0;
        }
        ll&res=dp[l][r];
        if(res==-1){
            for(ll in=l;in<=r;++in){
                ll ans=v[in];
                if(r<n-1){
                    ans*=v[r+1];
                }
                if(l>0){
                    ans*=v[l-1];
                }
                ans+=func(v, l, in-1)+func(v, in+1, r);
                res=max(res, ans);
            }
        }
        return res;
    }
    int maxCoins(vector<int>&v) {
        n=v.size();
        dp.assign(n, vi(ll)(n, -1));
        return func(v, 0, n-1);
    }
};