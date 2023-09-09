class Solution {
public:
    vector<int> nextGreaterElements(const vector<int>&v) {
        int n=v.size();
        vector<int>ans(n, INT_MIN);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(v[j]>v[i]){
                    ans[i] = v[j];
                    break;
                }
            }
            if(ans[i]==INT_MIN){
                for(int j=0; j<i; ++j){
                    if(v[j]>v[i]){
                        ans[i] = v[j];
                        break;
                    }
                }
            }
        }
        for(int&ele : ans){
            if(ele==INT_MIN){
                ele=-1;
            }
        }
        return ans;
    }
};