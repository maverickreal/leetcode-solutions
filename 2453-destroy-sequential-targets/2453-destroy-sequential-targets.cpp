class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int destroyTargets(vector<int>&v, int space) {
        unordered_map<ll,ll>ump;
        ll ans=-1, val=LLONG_MIN;
        sort(begin(v), end(v));
        for(ll i=v.size()-1;i>-1;--i){
            ll m=v[i]%space;
            if(++ump[m]>val || (ump[m]==val && v[i]<ans)){
                ans=v[i], val=ump[m];
            }
        }
        return ans;
    }
};