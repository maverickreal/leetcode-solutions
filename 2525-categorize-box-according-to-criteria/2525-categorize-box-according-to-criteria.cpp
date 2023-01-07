class Solution {
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    string categorizeBox(int l, int w, int h, int m) {
        bool first=l>=10000 || w>=10000 || h>=10000 || ll(l)*ll(w)*ll(h)>=1000000000, second=m>=100;
        if(first && second){
            return "Both";
        }
        if(!first && !second){
            return "Neither";
        }
        return (first?"Bulky":"Heavy");
    }
};