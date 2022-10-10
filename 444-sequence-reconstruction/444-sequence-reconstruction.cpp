class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool sequenceReconstruction(vector<int>&v, vector<vector<int>>&e) {
        ll n=v.size();
        vi(vi(ll))g(n);
        vi(ll)ind(n);
        for(const auto&it:e){
            for(ll i=1;i<it.size();++i){
                g[it[i-1]-1].pb(it[i]-1);
                ++ind[it[i]-1];
            }
        }
        list<ll>l;
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                l.pb(i);
            }
        }
        ll in=-1;
        while(!l.empty()){
            ll sz=l.size();
            if(sz!=1 || l.front()!=v[++in]-1){
                //cout<<sz<<' '<<l.front()<<' '<<v[in]<<nl;
                return false;
            }
            while(sz--){
                ll nd=l.front();
                l.pop_front();
                for(ll child:g[nd]){
                    if(--ind[child]==0){
                        l.pb(child);
                    }
                }
            }
        }
        return true;
    }
};