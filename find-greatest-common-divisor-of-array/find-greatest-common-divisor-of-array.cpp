class Solution {
    public:
    int findGCD(vector<int>&v) {
        return __gcd(*min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
    }
};