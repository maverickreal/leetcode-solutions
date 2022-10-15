class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool func(const vi(int)&v, ll n){
        if(v[0]>n){
            return 0;
        }
        ll cap=n-v[0];
        for(ll i=1;i<v.size();++i){
            if(v[i]<=n){
                cap+=n-v[i];
                continue;
            }
            ll dif=v[i]-n;
            if(dif>cap){
                return 0;
            }
            cap-=dif;
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>&v) {
        ll ans=*max_element(begin(v), end(v)), l=0, r=ans;
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(func(v, m)){
                ans=m, r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};