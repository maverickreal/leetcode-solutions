class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(pi))dp;
    ll funcInc(const vi(int)&v, ll in, ll rem, ll pre){
        if(rem==0){
            return 1;
        }
        if(in>=n){
            return 0;
        }
        ll&ans=rem==2?dp[in][pre].second:dp[in][pre].first;
        if(ans==-1){
            ans=funcInc(v, in+1, rem, pre);
            if(v[pre]<v[in]){
                ans+=funcInc(v, in+1, rem-1, in);
            }
        }
        return ans;
    }
    ll funcDec(const vi(int)&v, ll in, ll rem, ll pre){
        if(rem==0){
            return 1;
        }
        if(in>=n){
            return 0;
        }
        ll&ans=rem==2?dp[in][pre].second:dp[in][pre].first;
        if(ans==-1){
            ans=funcDec(v, in+1, rem, pre);
            if(v[pre]>v[in]){
                ans+=funcDec(v, in+1, rem-1, in);
            }
        }
        return ans;
    }
    int numTeams(vector<int>&v) {
        n=v.size();
        ll ans=0;
        dp.assign(n, vi(pi)(n, {-1,-1}));
        for(ll i=0;i<n;++i){
            ans+=funcInc(v, i+1, 2, i);
        }
        dp.assign(n, vi(pi)(n, {-1,-1}));
        for(ll i=0;i<n;++i){
            ans+=funcDec(v, i+1, 2, i);
        }
        return ans;
    }
};