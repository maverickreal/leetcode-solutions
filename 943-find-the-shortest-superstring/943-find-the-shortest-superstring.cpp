class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
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
        return ans;
    }
    ll getOverLap(const string&a, const string&b){
        ll m=a.size(), n=b.size();
        for(ll k=m-min(m,n);k<m;++k){
            if(a.substr(k)==b.substr(0, m-k)){
                return m-k;
            }
        }
        return 0;
    }
    string shortestSuperstring(vector<string>&v) {
        n=v.size();
        dp.assign(1<<n, vi(ll)(n, -1)), nxt.assign(1<<n, vi(ll)(n, -1)), overlap.assign(n, vi(ll)(n));
        for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                overlap[i][j]=getOverLap(v[i],v[j]);
            }
        }
        ll mx=-1, nxtIn=-1;
        for(ll i=0;i<n;++i){
            ll rec=func(v, 1<<i, i);
            if(rec>mx){
                mx=rec, nxtIn=i;
            }
        }
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
        }
        for(ll i=0;i<n;++i){
            if(!vis[i]){
                ans.append(v[i]);
            }
        }
        return ans;
    }
};