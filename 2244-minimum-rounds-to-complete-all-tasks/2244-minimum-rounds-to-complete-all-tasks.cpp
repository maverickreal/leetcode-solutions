class Solution {
public:
    int minimumRounds(vector<int>&v) {
        unordered_map<int, int>ump;
        for(const auto&i:v)
            ++ump[i];
        int res=0;
        for(const auto&ti:ump){
            int it=ti.second;
            if(it<2)
                return -1;
            if(it==2)
                ++res;
            else{
                res+=it/3;
                if(it%3)
                    ++res;
            }
        }
        return res;
    }
};