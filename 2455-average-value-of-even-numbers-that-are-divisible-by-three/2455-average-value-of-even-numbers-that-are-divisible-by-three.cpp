class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int averageValue(vector<int>&v) {
        ll sum=0, cnt=0;
        for(ll it:v){
            if(!(it&1) && !(it%3)){
                ++cnt, sum+=it;
            }
        }
        if(!cnt){
            return 0;
        }
        return sum/cnt;
    }
};