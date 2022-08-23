class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool validateStackSequences(vector<int>& a, vector<int>& b) {
        ll sz = a.size(), ptra = 0, ptrb = 0;
        list<ll>st;
        while (ptrb < sz) {
            if (st.empty() || st.back() != b[ptrb]) {
                if(ptra>=sz){
                    return false;
                }
                st.push_back(a[ptra++]);
            }
            else {
                ++ptrb;
                st.pop_back();
            }
        }
        return true;
    }
};