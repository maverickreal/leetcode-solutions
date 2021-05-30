class Solution {
public:
    int countGoodSubstrings(string s) {
        int sz = s.length(), res = 0;
        if (sz < 3)
            return 0;
        for (int i = 0;i < sz - 2;++i)
            if (!(s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2]))
                ++res;
        return res;
    }
};