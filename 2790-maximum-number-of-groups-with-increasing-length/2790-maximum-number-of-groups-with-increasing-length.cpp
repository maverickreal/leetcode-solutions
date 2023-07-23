class Solution {
public:
    typedef long long ll;
    int maxIncreasingGroups(vector<int>&v) {
        sort(begin(v), end(v));
        ll ans = 0, sum = 0;
        for(const int&it : v){
            sum += it;
            ll cnt = ans+1;
            ans += sum >= (cnt*(cnt+1))/2;
        }
        return ans;
    }
};