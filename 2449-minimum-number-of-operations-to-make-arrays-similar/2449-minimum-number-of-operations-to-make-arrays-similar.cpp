class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    long long makeSimilar(vector<int>&V, vector<int>&T) {
        vi(vi(ll))v(2), t(2);
        for(ll it:V){
            v[it&1].pb(it);
        }
        for(ll it:T){
            t[it&1].pb(it);
        }
        for(ll i=0;i<2;++i){
            sort(begin(v[i]), end(v[i])), sort(begin(t[i]), end(t[i]));
        }
        ll ans=0;
        for(ll i=0;i<v[0].size();++i){
            ans+=abs(v[0][i]-t[0][i])/2;
        }
        for(ll i=0;i<v[1].size();++i){
            ans+=abs(v[1][i]-t[1][i])/2;
        }
        return (ans/2);
    }
};