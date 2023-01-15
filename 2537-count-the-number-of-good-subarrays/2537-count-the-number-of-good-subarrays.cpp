class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    long long countGood(vector<int>&v, int k) {   
        unordered_map<ll,ll>ump;
        ll ans=0;
        for(ll tot=0, pre=0,in=0;in<v.size();++in){
            tot+=ump[v[in]]++;
            while(pre<in && tot>=k){
                tot-=--ump[v[pre++]];
            }
            ans+=pre;
            //cout<<in<< ' '<<ans<<' '<<tot<<' '<<pre<<' '<<ump[v[in]]<<' '<<nl;
        }
        return ans;
    }
};