class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int getCommon(vector<int>&u, vector<int>&v) {
        unordered_set<ll>ust;
        for(ll it:u){
            ust.insert(it);
        }
        for(ll it:v){
            if(ust.find(it)!=end(ust)){
                return it;
            }
        }
        return -1;
    }
};