class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int takeCharacters(const string&s, int k) {
        ll n=s.size(), af=0, bf=0, cf=0;
        for(char ch:s){
            if(ch=='a'){
                af++;
            }
            else if(ch=='b'){
                bf++;
            }
            else{
                cf++;
            }
        }
        if(af<k || bf<k || cf<k){
            return -1;
        }
        af-=k, bf-=k, cf-=k;
        ll ans=0, pre=0, ac=0, bc=0, cc=0;
        for(ll i=0;i<n;++i){
            if(s[i]=='a'){
                ac++;
            }
            else if(s[i]=='b'){
                bc++;
            }
            else{
                cc++;
            }
            while(pre<=i && (ac>af || bc>bf || cc>cf)){
                if(s[pre]=='a'){
                    ac--;
                }
                else if(s[pre]=='b'){
                    bc--;
                }
                else{
                    cc--;
                }
                ++pre;
            }
            ans=max(ans, i-pre+1);
        }
        return n-ans;
    }
};