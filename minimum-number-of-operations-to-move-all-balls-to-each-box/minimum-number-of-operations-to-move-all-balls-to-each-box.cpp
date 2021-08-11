class Solution {
public:
    vector<int> minOperations(string& s) {
        int sz = s.length(), o = s[0] == '1';
        vector<int>res(sz), res2(sz);
        for (int i = 1;i < sz;++i) {
            res[i] = o + res[i - 1];
            if (s[i] == '1')
                ++o;
        }
        o = s.back() == '1';
        for (int i = sz - 2;i > -1;--i) {
            res2[i] = res2[i + 1] + o;
            if (s[i] == '1')
                ++o;
        }
        for (int i = 0;i < sz;++i)
            res[i] += res2[i];
        return res;
    }
};