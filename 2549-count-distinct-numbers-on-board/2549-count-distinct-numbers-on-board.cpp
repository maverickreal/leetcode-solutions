class Solution {
typedef long long ll;
#define vi(x) vector<x>
public:
ll n;
vi(bool)dp;
void func(ll m){
    if(dp[m]){
        return;
    }
    dp[m]=1;
    for(ll i=1;i<=n;++i){
        if(m%i==1){
            func(i);
        }
    }
}

int distinctIntegers(ll N) {
    n=N, dp.resize(n+1);
    func(n);
    return accumulate(begin(dp), end(dp), 0LL);
}
};