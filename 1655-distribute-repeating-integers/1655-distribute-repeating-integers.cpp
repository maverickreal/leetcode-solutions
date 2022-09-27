class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, m;
    vi(ll)freq, cost;
    vi(vi(ll))dp;
    void getFreq(const vi(int)&v){
        vi(ll)ump(100001);
        for(ll it:v){
            ++ump[it];
        }
        for(auto it:ump){
            if(it>0){
                freq.pb(it);
            }
        }
    }
    void getCost(const vi(int)&q){
        for(ll bm=0;bm<cost.size();++bm){
            for(ll i=0;i<n;++i){
                if((bm>>i)&1){
                    cost[bm]+=q[i];
                }
            }
        }
    }
    bool func(const vi(int)&q, ll in, ll bm){
        if(__builtin_popcount(bm)==n){
            return true;
        }
        if(in==m){
            return false;
        }
        ll&ans=dp[bm][in];
        if(ans==-1){
            ans=0;
            for(ll it=bm;it<cost.size() && !ans;++it){
                //cout<<it<<' ';
                if(bm!=(it&bm) || freq[in]<cost[bm^it]){
                    continue;
                }
                freq[in]-=cost[bm^it];
                ans|=func(q, in+1, it);
                freq[in]+=cost[bm^it];
            }
        }
        //cout<<in<<' '<<freq[in]<<' '<<bm<<' '<<ans<<nl;
        return ans;
    }
    bool canDistribute(vector<int>&v, vector<int>&q) {
        getFreq(v);
        m=freq.size(), n=q.size();
        dp.assign(1<<n, vi(ll)(m, -1)), cost.assign(1<<n, 0);
        getCost(q);
        return func(q, 0, 0);
    }
};