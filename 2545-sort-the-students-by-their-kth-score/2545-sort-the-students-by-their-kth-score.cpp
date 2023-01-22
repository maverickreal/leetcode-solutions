class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    static bool cmp(const vi(int)&a, const vi(int)&b){
        ll k=a.back();
        return a[k]>b[k];
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(auto&it:score){
            it.pb(k);
        }
        sort(begin(score), end(score), cmp);
        for(auto&it:score){
            it.pop_back();
        }
        return score;   
    }
};