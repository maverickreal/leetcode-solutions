class Solution {
public:
    bool canBeIncreasing(vector<int>& v) {
        int sz = v.size();
        bool fl = true;
        for (int i = 1;i < sz;++i) {
            if (v[i] > v[i - 1])
                continue;
            if (!fl)//|| (i + 1 < sz && i > 1 && v[i + 1] <= v[i - 2]))
                return false;
            fl = false;
            if (i < 2 || v[i - 2] < v[i])
                continue;
            v[i] = v[i - 1];
        }
        return true;
    }
};