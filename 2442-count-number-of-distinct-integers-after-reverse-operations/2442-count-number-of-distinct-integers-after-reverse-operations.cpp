class Solution {
typedef long long ll;
#define vi(x) vector<x>
public:
    int countDistinctIntegers(vector<int>&v) {
        vi(bool)ump(1000001, 0);
        for(ll it:v){
            ump[it]=1;
            string str=to_string(it);
            reverse(begin(str), end(str));
            it=stoll(str);
            ump[it]=1;
        }
        ll ans=0;
        for(bool it:ump){
            ans+=it;
        }
        return ans;
    }
};