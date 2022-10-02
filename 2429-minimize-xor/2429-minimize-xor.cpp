class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int minimizeXor(const int a, const int b) {
        ll ans=0, rem=__builtin_popcount(b);
        for(ll i=31;i>-1;--i){
            if((a>>i)&1){
                if(rem>0){
                    //cout<<"x: "<<rem<<nl;
                    --rem;
                    ans|=1<<i;
                }
            }
            else{
                if(rem>i){
                    //cout<<"y: "<<rem<<nl;
                    ans|=1<<i;
                    --rem;
                }
            }
            //cout<<i<<' '<<ans<<nl;
        }
        return ans;
    }
};