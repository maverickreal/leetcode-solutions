class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

int maxNumOfMarkedIndices(vector<int>&v) {
    ll n=v.size();
    sort(begin(v), end(v));
    ll ans=0;
    for(ll l=0, r=n/2;l<n/2 && r<n;++r){
        if(2*v[l]<=v[r]){
            ans+=2, ++l;
        }
    }
    return ans;
}
};