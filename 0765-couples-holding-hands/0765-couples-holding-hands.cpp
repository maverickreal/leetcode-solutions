class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int minSwapsCouples(vector<int>&v) {
        ll n=v.size();
        vi(ll)pos(n);
        for(ll i=0;i<n;++i){
            pos[v[i]]=i;
        }
        ll ans=0;
        for(ll i=0;i<n-1;i+=2){
            ll opp=v[i];
            if(v[i]&1){
                --opp;
            }
            else{
                ++opp;
            }
            if(v[i+1]==opp){
                continue;
            }
            ll in=pos[opp];
            //cout<<i<<' '<<v[i]<<' '<<in<<' '<<v[in]<<nl;
            ++ans;
            ll nxt=v[i+1];
            swap(v[i+1], v[in]), swap(pos[nxt], pos[opp]);
        }
        // cout<<nl;
        // for(ll it:v){
        //     cout<<it<<' ';
        // }
        return ans;
    }
};