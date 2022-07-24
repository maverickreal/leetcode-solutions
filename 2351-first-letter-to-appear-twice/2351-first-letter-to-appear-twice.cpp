class Solution {
    typedef long long ll;
#define vi(x) vector<x>
public:
    char repeatedCharacter(string& s) {
        vi(bool)v(26);
        char res = '.';
        for (char ch : s) {
            if (v[ch - 'a']) {
                res = ch;
                break;
            }
            v[ch - 'a'] = true;
        }
        return res;
    }
};