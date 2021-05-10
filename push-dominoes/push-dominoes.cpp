class Solution {
public:
    string pushDominoes(string& s) {
        int sz = s.length();
        string res = "";
        s = "L" + s + "R";
        for (int i = 1, j = 0;i <= sz + 1;++i) {
            if (s[i] == '.')
                continue;
            if (j)
                res.push_back(s[j]);
            if (s[i] == s[j])
                res.append(string(i - j - 1, s[i]));
            else if (s[j] == 'L')
                res.append(string(i - j - 1, '.'));
            else {
                res.append(string((i - j - 1) >> 1, 'R'));
                if ((i - j - 1) % 2)
                    res.push_back('.');
                res.append(string((i - j - 1) >> 1, 'L'));
            }
            j = i;
        }
        return res;
    }
};