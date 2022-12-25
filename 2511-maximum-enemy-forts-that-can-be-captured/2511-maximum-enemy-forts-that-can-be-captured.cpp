class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll n;
ll func(const vi(int)&v){
    ll ans=0;
    for(ll i=0;i<n;++i){
        if(v[i]!=1){
            continue;
        }
        ll j=i+1;
        while(j<n && v[j]==0){
            ++j;
        }
        if(j>=n){
            break;
        }
        if(v[j]==-1){
            ans=max(ans, j-1-i);
        }
        i=j-1;
    }
    return ans;
}
    int captureForts(vector<int>&v) {
        n=v.size();
        ll ans=func(v);
        reverse(begin(v), end(v));
        ans=max(ans, func(v));
        return ans;
    }
};