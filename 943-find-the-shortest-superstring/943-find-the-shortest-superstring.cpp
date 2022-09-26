class Solution {
    typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp, nxt, overlap;
    ll func(const vi(string)&v, ll bm, ll pre){
        ll&ans=dp[bm][pre];
        if(ans==-1){
            for(ll in=0;in<n;++in){
                if((bm>>in)&1){
                    continue;
                }
                ll rec=func(v, bm|(1<<in), in)+overlap[pre][in];
                if(rec>ans){
                    ans=rec, nxt[bm][pre]=in;
                }
            }
        }
        if(ans==-1){
            ans=0;
        }
        //cout<<bm<<' '<<pre<<' '<<ans<<' '<<nxt[bm][pre]<<nl;
        return ans;
    }
    string shortestSuperstring(vector<string>&v) {
        n=v.size();
        dp.assign(1<<n, vi(ll)(n, -1)), nxt.assign(1<<n, vi(ll)(n, -1)), overlap.assign(n, vi(ll)(n, 0));
        for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                for(ll k=v[i].size()-min(v[i].size(), v[j].size());k<v[i].size();++k){
                    if(v[i].substr(k)==v[j].substr(0, v[i].size()-k)){
                        overlap[i][j]=v[i].size()-k;
                        break;
                    }
                }
                //cout<<overlap[i][j]<<' ';
            }
            //cout<<nl;
        }
        //cout<<nl;
        ll mx=-1, nxtIn=-1;
        for(ll i=0;i<n;++i){
            ll rec=func(v, 1<<i, i);
            if(rec>mx){
                mx=rec, nxtIn=i;
            }
        }
        // for(ll i=0;i<(1<<n);++i){
        //     cout<<i<<"  ";
        //     for(ll j=0;j<n;++j){
        //         cout<<nxt[i][j]<<' ';
        //     }
        //     cout<<nl;
        // }
        //cout<<mx<<' '<<nxtIn;
        vi(bool)vis(n);
        ll bm=1<<nxtIn, pre=nxtIn;
        string ans=v[nxtIn];
        vis[nxtIn]=true;
        nxtIn=nxt[bm][nxtIn];
        while(nxtIn>-1){
            bm|=1<<nxtIn;
            ans.append(v[nxtIn].substr(overlap[pre][nxtIn]));
            vis[nxtIn]=true;
            pre=nxtIn;
            nxtIn=nxt[bm][nxtIn];
            //cout<<nxtIn<<' '<<bm<<nl;
        }
        for(ll i=0;i<n;++i){
            if(!vis[i]){
                //cout<<i<<' ';
                ans.append(v[i]);
            }
        }
        return ans;
    }
};