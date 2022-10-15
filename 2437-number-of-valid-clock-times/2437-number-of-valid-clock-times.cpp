class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool valid(const string&s){
        ll h=stoll(s.substr(0, 2)), m=stoll(s.substr(3, 2));
        return (h>=0 && h<=23 && m>=0 && m<=59);
    }
    int countTime(string&s, ll in=0) {
        if(in==5){
            return valid(s);
        }
        if(s[in]!='?'){
            return countTime(s,in+1);
        }
        ll ans=0;
        for(ll i=0;i<=9;++i){
            s[in]='0'+i;
            ans+=countTime(s, in+1);
        }
        s[in]='?';
        return ans;
    }
};