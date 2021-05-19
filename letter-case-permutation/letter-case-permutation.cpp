class Solution {
public:
    vector<string>res;
    int sz;
    void func(string s, int i = 0) {
        if (i == sz) {
            res.push_back(s);
            return;
        }
        func(s, i + 1);
        if (s[i] > 96) {
            s[i] -= 32;
            func(s, i + 1);
        }
        else if (s[i] > 64) {
            s[i] += 32;
            func(s, i + 1);
        }
    }
    vector<string> letterCasePermutation(const string& s) {
        sz = s.length();
        func(s);
        return res;
    }
};