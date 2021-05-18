class Solution {
public:
    string reverseVowels(string& s) {
        unordered_set<char>ust = { 'a','e','i','o','u','A','E','I','O','U' };
        int i = 0, j = s.length() - 1;
        while (i < j) {
            //cout<<i<<' '<< j<<'\n';
            if (ust.find(s[i]) != ust.end() && ust.find(s[j]) != ust.end()) {
                s[i] += s[j];
                s[j] = s[i] - s[j];
                s[i] -= s[j];
                ++i,--j;
                continue;
            }
            if (ust.find(s[i]) != ust.end())
                --j;
            else if (ust.find(s[j]) != ust.end())
                ++i;
            else {
                ++i;
                --j;
            }
        }
        return s;
    }
};