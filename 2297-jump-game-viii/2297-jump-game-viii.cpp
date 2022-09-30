class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(ll)ng, ns, dp;
    void doNge(const vi(int)&v){
        ng.assign(n, n);
        list<ll>l;
        for(ll i=0;i<n;++i){
            while(!l.empty() && v[i]>=v[l.back()]){
                ng[l.back()]=i;
                l.pop_back();
            }
            l.pb(i);
        }
    }
    void doNse(const vi(int)&v){
        ns.assign(n, n);
        list<ll>l;
        for(ll i=0;i<n;++i){
            while(!l.empty() && v[i]<v[l.back()]){
                ns[l.back()]=i;
                l.pop_back();
            }
            l.pb(i);
        }
    }
    ll func(const vi(int)&c, const vi(int)&v, ll in){
        if(in>=n){
            return LLONG_MAX;
        }
        ll&ans=dp[in];
        if(ans==-1){
            ans=c[in];
            if(in<n-1){
                ll rec=min(func(c, v, ng[in]), func(c, v, ns[in]));
                if(rec<LLONG_MAX){
                    ans+=rec;
                }
                else{
                    ans=LLONG_MAX;
                }
            }
        }
        return ans;
    }
    long long minCost(vector<int>&v, vector<int>&c) {
        n=v.size();
        c[0]=0;
        dp.assign(n, -1);
        doNse(v), doNge(v);
        return func(c, v, 0);
    }
};