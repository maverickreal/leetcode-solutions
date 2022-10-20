class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    unordered_set<string>ust;
    string ans;
    ll tot;
    bool func(const int&n, const int&k, string&s){
        if(ust.size()==tot){
            ans=s;
            return true;
        }
        for(ll i=0;i<k;++i){
            s.pb('0'+i);
            ll sz=s.size();
            if(sz<n){
                if(func(n, k, s)){
                    return true;
                }
                s.pop_back();
                continue;
            }
            string recent=s.substr(sz-n);
            if(ust.find(recent)==ust.end()){
                ust.insert(recent);
                if(func(n, k, s)){
                    return true;
                }
                ust.erase(recent);
            }
            s.pop_back();
        }
        return false;
    }
    string crackSafe(int n, int k) {
        tot=pow(k, n);
        string s;
        func(n, k, s);
        // for(auto it:ust){
        //     cout<<it<<' ';
        // }
        return ans; 
    }
};