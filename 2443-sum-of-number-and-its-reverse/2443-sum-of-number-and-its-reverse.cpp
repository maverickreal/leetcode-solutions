class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool sumOfNumberAndReverse(int n) {   
        for(ll i=0;i<=n;++i){
            string str=to_string(i);
            reverse(begin(str), end(str));
            ll j=stoll(str);
            if(i+j==n){
                return 1;
            }
        }
        return 0;
    }
};