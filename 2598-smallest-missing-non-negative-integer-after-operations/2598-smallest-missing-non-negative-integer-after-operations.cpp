class Solution {
public:
    int findSmallestInteger(vector<int>&v, int k) {
        vector<int>ump(100001);
        for(int it:v){
            ++ump[(k+it%k)%k];
        }
        for(int i=0;i<v.size();++i){
            if(--ump[i%k]==-1){
                return i;
            }
        }
        return v.size();
    }
};