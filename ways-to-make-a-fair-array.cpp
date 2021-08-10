class Solution {
public:
    int waysToMakeFair(vector<int>& v) {
        int sz = v.size();
        if (sz == 1) return sz;
        vector <int> dpo(sz), dpe = dpo;
        for (int i = 0;i < sz;++i) {
            if (i) {
                dpo[i] = dpo[i - 1];
                dpe[i] = dpe[i - 1];
            }
            if ((i + 1) & 1)
                dpo[i] += v[i];
            else
                dpe[i] += v[i];
        }
        int res = (dpo.back() - dpo.front() == dpe.back() - dpe.front()) + (dpo[sz - 2] == dpe[sz - 2]);
        for (int i = 1;i < sz - 1;++i)
            if ((dpo[i - 1] + dpe.back() - dpe[i]) << 1 == dpe.back() + dpo.back() - v[i])
                ++res;
        return res;
    }
};