class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int sz = v.size(), i = 0;
        if (sz < 3)
            return 0;
        long res=0;
        int dif = v[1] - v[0], j = 0;
        while (++i < sz) {
            if (v[i] - v[i - 1] == dif) {
                if (i == sz - 1) {
                    int m = i - j - 1;
                    res += (m * (m + 1)) >> 1;
                }
                continue;
            }
            int m = i - j - 2;
            res += (m * (m + 1)) >> 1;
            dif = v[i] - v[i - 1];
            j = i - 1;
        }
        return res;
    }
};