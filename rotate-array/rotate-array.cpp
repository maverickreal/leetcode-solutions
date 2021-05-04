class Solution {
public:
    void rotate(vector<int>&v, int k) {
        int sz=v.size(), i=0;
        k%=sz;
        while(i<sz-k)
            v.push_back(v[i++]);
        v.erase(v.begin(),v.begin()+i);
    }
};