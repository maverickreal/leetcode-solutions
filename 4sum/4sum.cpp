class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        long tar = t;
        int sz = v.size();
        set<vector<int>>st;
        sort(v.begin(), v.end());
        for (int i = 0;i < sz - 3;++i) {
            for (int j = i + 1;j < sz - 2;++j) {
                for (int k = j + 1;k < sz - 1;++k) {
                    auto it = lower_bound(v.begin() + k + 1, v.end(), tar - v[i] - v[j] - v[k]);
                    while (it != v.end() && *it == tar - v[i] - v[j] - v[k]) {
                        st.insert({ v[i],v[j],v[k],*it });
                        ++it;
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};