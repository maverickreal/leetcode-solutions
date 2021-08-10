class Solution {
public:
#define ll long long
    long long numberOfWeeks(vector<int>& v) {
        ll sum = accumulate(v.begin(), v.end(), (ll)0);
        ll max = *max_element(v.begin(), v.end());
        if (max <= (sum >> 1))
            return sum;
        return ((sum - max) << 1) + 1;
    }
};