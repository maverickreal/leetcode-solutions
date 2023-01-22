class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    //unordered_map<ll,pi>ump;
    vi(vi(ll))dp;
    vi(pi)ump;
    ll sz, k;
    ll func(const vi(int)&v, ll in, ll start, ll cnt){
        if(start>=sz){
            return 0;
        }
        if(in==sz){
            return cnt+k;
        }
        ll&ans=dp[in][start];
        if(ans==-1){
            // if(ump.find(v[in])==end(ump)){
            //     ump[v[in]]={0, -1};
            // }
            auto [pf, pts]=ump[v[in]];
            ll newCnt=cnt;
            if(pts!=start){
                ump[v[in]]={1, start};
            }
            else{
                ++ump[v[in]].first;
                if(ump[v[in]].first==2){
                    newCnt+=2;
                }
                else if(ump[v[in]].first>2){
                    ++newCnt;
                }
            }
            ans=min(k+newCnt+func(v, in+1, in+1, 0), func(v, in+1, start, newCnt));
            ump[v[in]]={pf, pts};
            //cout<<start<<' '<<in<<' '<<newCnt<<' '<<ans<<nl;
        }
        return ans;
    }
    int minCost(vector<int>&v, int K) {
        sz=v.size(), k=K;
        dp.resize(sz, vi(ll)(sz, -1)), ump.resize(sz, {0, -1});
        return func(v, 0, 0, 0);
    }
};