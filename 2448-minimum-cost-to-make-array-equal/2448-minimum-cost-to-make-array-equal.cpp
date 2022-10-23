class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, l, r, ans;
    ll getCost(const vi(int)&v, const vi(int)&c, ll m){
        ll ans=0;
        for(ll i=0;i<n;++i){
            ans+=abs(v[i]-m)*c[i];
        }
        return ans;
    }
    ll minCost(vector<int>&v, vector<int>&c) {
        n=v.size(), l=1, r=1e6, ans=-1;
        while(l<=r){
            ll m=l+((r-l)>>1);
            ll cost=getCost(v, c, m);
            if(l==r){
                ans=cost;
                break;
            }
            ll preCost=getCost(v, c, m-1), postCost=getCost(v, c, m+1);
            if(preCost>cost && cost<postCost){
                ans=cost;
                break;
            }
            if(preCost<cost){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};