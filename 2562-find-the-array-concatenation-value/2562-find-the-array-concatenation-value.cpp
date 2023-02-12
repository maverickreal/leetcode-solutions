class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9+7;
const char nl = '\n';

long long findTheArrayConcVal(vector<int>&v) {
    ll n=v.size(), ans=0, l=0, r=n-1;
    while(l<r){
        ans+=stoll(to_string(v[l++])+to_string(v[r--]));
    }
    if(l==r){
        ans+=v[l];
    }
    return ans;
}
};