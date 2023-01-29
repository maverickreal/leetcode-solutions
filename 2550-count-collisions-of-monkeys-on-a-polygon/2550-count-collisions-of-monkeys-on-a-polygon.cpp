class Solution {
public:
typedef long long ll;
ll modExp(ll x, ll y, ll m){
    ll res = 1;
    x%=m;
    if (!x){
        return 0;  
    }
    while (y > 0){
        if (y & 1){
            res = (res*x) % m;
        }
        y>>=1;
        x = (x*x) % m;
    }
    return res;
}

int monkeyMove(int n) {
    ll mod=1e9+7;
    return (mod+modExp(2, n, mod)-2)%mod;
}
};