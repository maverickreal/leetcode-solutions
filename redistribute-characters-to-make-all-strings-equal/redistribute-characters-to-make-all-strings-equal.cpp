class Solution {
public:
    bool makeEqual(vector<string>& v) {
        int sz = v.size();
        vector<int>ump(26);
        for (const string& s : v) {
            for (const char& ch : s)
                ++ump[ch - 'a'];
        }
        for (const int& i : ump)
            if (i % sz)
                return false;
        return true;
    }
};