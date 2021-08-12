class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        int sz = v.size();
        map<vector<int>, vector<string>>mp;
        for (string& s : v) {
            vector<int>tmp(26);
            for (char& ch : s)
                ++tmp[ch - 'a'];
            mp[tmp].push_back(s);
        }
        vector<vector<string>>res;
        for (auto& it : mp)
            res.push_back(it.second);
        return res;
    }
};