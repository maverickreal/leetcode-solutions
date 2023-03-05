class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

void getPrimeFactors(ll n, vi(ll)&v){
    for (ll i = 2; i*i<=n; ++i){
        if(n%i){
            continue;
        }
        v.pb(i);
        while (n % i == 0){
            n/=i;
        }
    }
    if (n > 2){
        v.pb(n);
    }
}

int findValidSplit(vector<int>&v) {
    unordered_map<ll,ll>l, r;
    for(ll it:v){
        vi(ll)pf;
        getPrimeFactors(it, pf);
        for(ll ti:pf){
            ++r[ti];
        }
    }
    for(ll i=0;i<v.size()-1;++i){
        vi(ll)pf;
        getPrimeFactors(v[i], pf);
        for(ll j:pf){
            if(--r[j]==0){
                l.erase(j);
            }
            else{
                ++l[j];
            }
        }
        if(l.empty()){
            return i;
        }
    }
    return -1;
}
};