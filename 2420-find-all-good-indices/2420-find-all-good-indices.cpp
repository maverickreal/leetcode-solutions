class Solution {
    typedef long long ll;
typedef pair<string, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool bs(const vi(ll)&v, ll i, ll j){
        ll l=0, r=v.size()-1;
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(v[m]>=i && v[m]<=j){
                return true;
            }
            if(v[m]<i){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return false;
    }
    vector<int> goodIndices(vector<int>&v, int k) {
        ll n=v.size();
        vi(ll)left, right;
        for(ll i=1;i<n;++i){
            if(v[i]>v[i-1]){
                left.pb(i);
            }
            if(v[i]<v[i-1]){
                right.pb(i);
            }
        }
        vi(int)ans;
        for(ll i=k;i<n-k;++i){
            if(!(bs(left, i-k+1, i-1) || bs(right, i+2, i+k))){
                ans.pb(i);
            }
        }
        return ans;
    }
};