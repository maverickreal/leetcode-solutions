class Solution {
public:
    typedef long long ll;
    int findPeakElement(vector<int>& v) {
        const ll sz = v.size(), mn = -2147483650;
        ll i = 0, j = sz - 1;
        while (i < j) {
            ll m = i + ((j - i) >> 1), l = (m ? v[m - 1] : mn), r = (m < sz - 1 ? v[m + 1] : mn);
            if (l<v[m] && v[m]>r)
                break;
            if (r > v[m] && v[m] > l)
                i = m + 1;
            else
                j = m - 1;
        }
        return i + ((j - i) >> 1);
    }
};