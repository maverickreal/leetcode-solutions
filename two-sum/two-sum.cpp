class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int sz=v.size();
        unordered_map<int,int>ump;
        vector<int>res;
        for(int i=0;i<sz;++i){
            if(ump.find(t-v[i])!=ump.end()){
                res={ump[t-v[i]],i};
                break;
            }
            ump[v[i]]=i;
        }
        return res;
    }
};