class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
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
ll factorial(ll n){
    ll ans=1;
    for(ll i=1;i<=n;++i){
        ans=(ans*i)%mod;
    }
    return ans;
}
ll duplicate(const string&s){
    vi(ll)ump(26);
    for(const char&ch:s){
        ++ump[ch-'a'];
    }
    ll ans=1;
    for(ll it:ump){
        ans=(ans*factorial(it))%mod;
    }
    return ans;
}
void getWords(const string&s, vi(string)&v){
    string str;
    for(char ch:s){
        if(ch==' '){
            v.pb(str);
            str.clear();
        }
        else{
            str.pb(ch);
        }
    }
    v.pb(str);
}
int countAnagrams(const string&s) {
    vi(string)words;
    getWords(s, words);
    ll ans=1;
    for(const string&word:words){
        ll denomInv=duplicate(word);
        denomInv=modExp(denomInv, mod-2, mod);
        ans=((ans*factorial(word.size()))%mod*denomInv)%mod;
    }
    return ans;
}
};