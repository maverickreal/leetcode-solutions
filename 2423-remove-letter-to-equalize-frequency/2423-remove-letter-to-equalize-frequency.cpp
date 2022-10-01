class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool func(const vi(ll)&v){
        ll pre=-1;
        for(ll it:v){
            if(!it){
                continue;
            }
            if(pre==-1){
                pre=it;
                continue;
            }
            if(pre!=it){
                return false;
            }
        }
        return true;
    }
    bool equalFrequency(const string&s) {
        vi(ll)ump(26);
        for(char ch:s){
            ++ump[ch-'a'];
        }
        for(ll i=0;i<26;++i){
            if(!ump[i]){
                continue;
            }
            --ump[i];
            if(func(ump)){
                return true;
            }
            ++ump[i];
        }
        return false;
    }
};