class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int edgeScore(vector<int>&v) {
        ll n=v.size();
        vi(ll)ump(n);
        for(ll i=0;i<n;++i){
            ump[v[i]]+=i;
        }
        ll ans=-1, in=-1;
        for(ll i=0;i<n;++i){
            if(ump[i]>ans){
                ans=ump[i], in=i;
            }
        }
        return in;
    }
};