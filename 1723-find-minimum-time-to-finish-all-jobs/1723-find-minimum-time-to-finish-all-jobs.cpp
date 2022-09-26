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
    vi(ll)cost;
    ll getCost(const vi(int)&v, ll bm){
        ll ans=0;
        for(ll i=0;i<n;++i){
            if((bm>>i)&1){
                ans+=v[i];
            }
        }
        return ans;
    }
    ll func(const vi(int)&v, ll bm, ll k){
        if(bm==0){
            return 0;
        }
        if(k<1){
            return LLONG_MAX;
        }
        ll&ans=dp[bm][k];
        if(ans==-1){
            ans=LLONG_MAX;
            for(ll it=bm;;it=(it-1)&bm){
                ans=min(ans, max(cost[bm^it], func(v, it, k-1)));
                if(it<1){
                    break;
                }   
            }
        }
        return ans;
    }
    int minimumTimeRequired(vector<int>&v, int k) {
        n=v.size();
        cost.assign(1<<n, 0);
        for(ll bm=0;bm<(1<<n);++bm){
            cost[bm]=getCost(v, bm);
        }
        dp.assign(1<<n, vi(ll)(k+1, -1));
        return func(v, (1<<n)-1, k);
    }
};