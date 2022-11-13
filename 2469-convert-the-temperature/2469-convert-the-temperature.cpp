class Solution {
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<double> convertTemperature(ld celsius) {
        return vi(ld)({celsius+ld(273.15), (celsius*ld(1.80))+ld(32.00)});
    }
};