class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int sz = v.size(), cnt = 0;
        for (int i = 1;i < sz;++i) {
            if (v[i] == v[i - 1])
                ++cnt;
            else
                v[i - cnt] = v[i];
        }
        // for(int i:v)
        //     cout<<i<<' ';
        // cout<<'\n'<<cnt;
        return sz-cnt;
    }
};