class Solution {
typedef int ll;
#define vi(x) vector<x>
public:
    vi(ll)st; // Segment Tree
    ll n; // num of nodes/items
    ll findGcd(ll ss, ll se, ll qs, ll qe, ll si){
        if (ss > qe || se < qs){
            return 0;
        }
        if (qs <= ss && qe >= se){
            return st[si];
        }
        ll m = ss + ((se - ss)>>1);
        return __gcd(findGcd(ss, m, qs, qe, si * 2 + 1), findGcd(m + 1, se, qs, qe, si * 2 + 2));
    }

    ll constructST(const vi(ll)&v, ll ss, ll se, ll si){
        if (ss == se) {
            return (st[si] = v[ss]);
        }
        ll m = ss + ((se - ss)>>1);
        return (st[si] = __gcd(constructST(v, ss, m, si * 2 + 1), constructST(v, m + 1, se, si * 2 + 2)));
    }

    int subarrayGCD(vector<int>&v, int k) {
        n=v.size();
        ll height = ceil(log2(n));
        st.resize(2 * (1LL<<height) - 1);
        constructST(v, 0, n - 1, 0);
        ll ans=0;
        for(ll i=0;i<n;++i){
            for(ll j=i;j<n;++j){
                ans+=findGcd(0, n - 1, i, j, 0)==k;
            }
        }
        return ans;
    }
};