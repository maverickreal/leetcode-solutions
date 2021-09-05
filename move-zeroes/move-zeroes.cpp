class Solution {
public:
    void moveZeroes(vector<int>&v) {
       int sz=v.size(); 
        int i=-1;
        while(++i<sz && v[i]);
        if(i==sz)
            return;
        for(int j=i;i<sz && j<sz;++j){
            if(v[j]){
                v[i++]=v[j];
                v[j]=0;
            }
        }
    }
};