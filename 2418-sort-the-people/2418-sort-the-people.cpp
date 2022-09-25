class Solution {
    typedef long long ll;
typedef pair<string, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    static bool cmp(const pi&a, const pi&b){
        return (a.second>b.second);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ll n=names.size();
        vi(pi)v(n);
        for(ll i=0;i<n;++i){
            v[i]={names[i], heights[i]};
        }
        sort(v.begin(), v.end(), cmp);
        for(ll i=0;i<n;++i){
            names[i]=v[i].first;
        }
        return names;
    }
};