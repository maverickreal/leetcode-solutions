class Solution {
    typedef long long ll;
#define vi(x) vector<x>
public:
    char repeatedCharacter(string& s) {
        ll mask=0;
        char res = '.';
        for (char ch : s) {
            if (mask&(1<<(ch-'a'))) {
                res = ch;
                break;
            }
            mask|=(1<<(ch-'a'));
        }
        return res;
    }
};