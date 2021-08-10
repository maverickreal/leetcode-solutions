class Solution {
public:
    string removeOccurrences(string& s, string& p) {
        int szp = p.length();
        for (int i = 0, j = 0;i < s.length();++i) {
            if (i - j + 1 < szp)
                continue;
            if (s.substr(j, i - j + 1) == p) {
                s.erase(j, i - j + 1);
                j = i = max(-1, j - szp);
            }
            ++j;
        }
        return s;
    }
};