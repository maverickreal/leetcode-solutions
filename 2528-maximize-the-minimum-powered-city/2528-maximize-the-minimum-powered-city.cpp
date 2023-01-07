class Solution {
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    bool func(const vi(int)&v, ll r, ll k, ll m){
        ll n=v.size(), sum=0, rem=k;
        vi(ll)pre(n);
        for(ll in=0;in<n;++in){
            ll i=max(0LL, in-r), j=min(n-1, in+r);
            pre[i]+=v[in];
            if(j+1<n){
                pre[j+1]-=v[in];
            }
        }
        for(ll i=0;i<n;++i){
            sum+=pre[i];
            if(sum>=m){
                continue;
            }
            ll dif=m-sum;
            if(dif>rem){
                return 0;
            }
            sum+=dif, rem-=dif;
            if(i+(2*r)+1<n){
                pre[i+(2*r)+1]-=dif;
            }
        }
        return 1;
    }
    long long maxPower(vector<int>&v, int r, int k) {
        ll n=v.size(), x=0, y=1e18, ans=-1;
        while(x<=y){
            ll m=x+((y-x)>>1);
            if(func(v, r, k, m)){
                ans=m, x=m+1;
            }
            else{
                y=m-1;
            }
        }
        return ans;
    }
};