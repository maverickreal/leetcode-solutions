class Solution {
public:
    string shiftingLetters(string& s, vector<int>& v) {
        int sz = s.length();
        s.back() = 'a' + ((s.back() - 'a' + v.back()) % 26);
        for (int i = sz - 2;i > -1;--i) {
            v[i] =(v[i]+ v[i + 1])%26;
            s[i] = 'a' + ((s[i] - 'a' + v[i]) % 26);
        }
        return s;
    }
};