class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& v) {
        int sz = v.size();
        set<vector<int>> st = { {},{v.back()} };
        for (int i = sz - 2;i > -1;--i) {
            int sz2 = st.size();
            vector<vector<int>>tmp(st.begin(), st.end());
            for (int j = 0;j < sz2;++j) {
                if (tmp[j].empty() || v[i] <= tmp[j].back()) {
                    auto it = tmp[j];
                    it.push_back(v[i]);
                    st.insert(it);
                }
            }
        }
        vector<vector<int>>res(st.begin(), st.end());
        for (int i = 0;i < res.size();++i) {
            if (res[i].size() < 2) {
                res.erase(res.begin() + i);
                --i;
            }
            else
                reverse(res[i].begin(), res[i].end());

        }
        return res;
    }
};