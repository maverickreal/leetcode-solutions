class Solution {
public:
    vector<int> searchRange(vector<int>& v, int tar) {
        int i = 0, j = v.size() - 1, l = INT_MAX, r = INT_MIN;
        bool fl = true;
        while (i <= j) {
            if (i == j) {
                if (fl)
                    fl = false;
                else
                    break;
            }
            int m = i + ((j - i) >> 1);
            if (v[m] == tar) {
                l = min(l, m);
                j = m - 1;
                continue;
            }
            if (v[m] > tar)
                j = m - 1;
            else
                i = m + 1;
        }
        if (l == INT_MAX)
            return { -1,-1 };
        i = l, j = v.size() - 1;
        fl = true;
        while (i <= j) {
            if (i == j) {
                if (fl)
                    fl = false;
                else
                    break;
            }
            int m = i + ((j - i) >> 1);
            if (v[m] == tar) {
                r = max(r, m);
                i = m + 1;
                continue;
            }
            if (v[m] > tar)
                j = m - 1;
            else
                i = m + 1;
        }
        return { l,r };
    }
};