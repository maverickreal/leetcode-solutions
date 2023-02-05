class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
    bool isVowel(const char&ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    vector<int> vowelStrings(vector<string>&v, vector<vector<int>>&q) {
        ll n=v.size(), m=q.size();
        vi(ll)pre(n);
        pre[0]=isVowel(v[0][0]) && isVowel(v[0].back());
        for(ll i=1;i<n;++i){
            pre[i]=pre[i-1]+(isVowel(v[i][0]) && isVowel(v[i].back()));
        }
        vi(int)ans(m);
        for(ll i=0;i<m;++i){
            ll l=q[i][0], r=q[i][1];
            ans[i]=pre[r]-(l?pre[l-1]:0);
        }
        return ans;
    }
};