class Solution {
public:
    int rob(const vector<int>&v){
        int sz=v.size(), prepre=v[0];
        if(sz==1){
            return prepre;
        }
        int pre=max(v[0], v[1]), ans=pre;
        for(int i=2; i<sz-1; ++i){
            int cur=max(pre, prepre+v[i]);
            prepre=pre, pre=cur;
            ans=max(ans, cur); 
        }
        if(sz==2){
            return ans;
        }
        prepre=v[1], pre=max(prepre, v[2]), ans=max(ans, pre);
        for(int i=3; i<sz; ++i){
            int cur=max(pre, prepre+v[i]);
            prepre=pre, pre=cur;
            ans=max(ans, cur);
        }
        return ans;
    }
};