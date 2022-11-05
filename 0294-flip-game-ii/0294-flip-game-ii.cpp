class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll n;
unordered_map<string, bool>ump; 
bool func(const string&s){
    if(s.size()<2){
        return 0;
    }
    if(ump.find(s)==ump.end()){
        ump[s]=0;
        for(ll k=0;k<s.size()-1;++k){
            if(s[k]=='+' && s[k+1]=='+' && !func(s.substr(0, k)+"-"+s.substr(k+2))){
                    ump[s]=1;
                    break;
            }
        }
    }
    return ump[s];
}
    bool canWin(const string&s) {
        n=s.size();
        return func(s);    
    }
};