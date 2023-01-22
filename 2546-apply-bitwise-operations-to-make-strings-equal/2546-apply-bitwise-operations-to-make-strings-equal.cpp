class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool makeStringsEqual(string&s, string&t){
        ll o=0, z=0, cz=0, co=0, n=s.size();
        for(ll i=0;i<n;++i){
            if(s[i]=='0'){
                ++z, cz+=t[i]=='1';
            }
            else{
                ++o, co+=t[i]=='0';
            }
        }
        if(!cz && !co){
            return 1;
        }
        if(cz && !o){
            return 0;
        }
        o+=cz;
        return (o>co);
    }
};