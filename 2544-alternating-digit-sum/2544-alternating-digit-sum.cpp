class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int alternateDigitSum(int n) {
        bool p=1;
        ll ans=0;
        for(char ch:to_string(n)){
            if(p){
                ans+=ch-'0';
            }
            else{
                ans-=ch-'0';
            }
            p=!p;
        }
        return ans;
    }
};