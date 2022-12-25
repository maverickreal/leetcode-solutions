class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
ll n;
    int maximumTastiness(vector<int>&v, int k) {
        n=v.size();
        ll l=0, r=mod, ans=-1;
        sort(begin(v), end(v));
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(ok(v, k, m)){
                ans=m, l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
    bool ok(const vi(int)&v, ll k, ll m){
        ll pre=v[0], cnt=1;
        for(ll i=1;i<n && cnt<k;++i){
            if(v[i]-pre>=m){
                pre=v[i], ++cnt;
            }
        }
        return (cnt==k);
    }
};