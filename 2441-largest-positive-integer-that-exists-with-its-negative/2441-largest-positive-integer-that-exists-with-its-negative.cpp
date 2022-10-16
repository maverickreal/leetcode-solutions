class Solution {
typedef long long ll;
public:
    int findMaxK(vector<int>&v) {
        set<ll>st(begin(v), end(v));
        for(auto it=st.rbegin(); it!=st.rend();++it){
            if(st.find(-*it)!=st.end()){
                return *it;
            }
        }
        return -1;
    }
};