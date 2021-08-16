class Solution {
public:
    string minWindow(string& s, string& t) {
        int szs = s.length(), szt = t.length();
        string res(szs + szt, '.');
        if (szt > szs)
            return "";
        unordered_map<char, int>vt, vs;
        for (char& ch : t)
            ++vt[ch];
        for (int i = 0, j = 0;j < szs;++j) {
            ++vs[s[j]];
            bool fl = true;
            for (auto& it : vt) {
                char ch = it.first;
                if (vt[ch] > vs[ch]) {
                    fl = false;
                    break;
                }
            }
            if (!fl)
                continue;
            for (;i < j;++i) {
                if (vs[s[i]] == vt[s[i]])
                    break;
                --vs[s[i]];
            }
            if (j - i + 1 < res.length())
                res = s.substr(i, j - i + 1);
        }
        for (char& ch : t)
            if (vt[ch] > vs[ch])
                return "";
        return res;
    }
};