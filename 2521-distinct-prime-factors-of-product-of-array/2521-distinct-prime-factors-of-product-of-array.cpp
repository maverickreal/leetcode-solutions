class Solution {
typedef long long ll;
public:
    unordered_set<ll>pf, cache; // hash-set of all the prime factors of all the numbers
    void getPrimeFactors(ll n){
        ll m=n;
        if(n<2){
            return;
        }
        while (!(n&1)){
            pf.insert(2);
            n>>=1;
        }
        for (ll i = 3; i*i<=n; i+=2){
            while (n % i == 0){
                pf.insert(i);
                n/=i;
            }
        }
        if (n > 2){
            pf.insert(n);
        }
    }
    int distinctPrimeFactors(vector<int>&v) {
    ll ans=0;
    for(ll it:v){
        getPrimeFactors(it);
    }
    return pf.size();
    }
};