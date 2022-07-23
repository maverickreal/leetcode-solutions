class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int numSteps(string& s) {
        ll sz = s.length(), ans = 0, car = 0;
        while (s.length() > 1) {
            ++ans;
            if(s.back()=='0' && car){
                --car;
                s.back()='1';
            }
            if ((s.back() == '1' && !(car & 1)) || (s.back() == '0' && car & 1)) {
                ++ans;
                ++car;
            }
            s.pop_back();
            //cout<<s<<' '<<ans<<' '<<car<<nl;
        }
        if (car & 1 && s.back() == '1') {
            ++ans;
        }
        return ans;
    }
};