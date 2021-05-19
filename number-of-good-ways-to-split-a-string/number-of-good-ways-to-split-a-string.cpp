class Solution {
public:
    int numSplits(string& s) {
        int sz = s.length(), res = 0;
        unordered_map<char, int>ump, ump2;
        for (const char& ch : s)
            ++ump2[ch];
        for (int i = 0;i < sz - 1;++i) {
            ++ump[s[i]];
            --ump2[s[i]];
            if (!ump2[s[i]])
                ump2.erase(s[i]);
            res += ump.size() == ump2.size();
        }
        return res;
    }
};