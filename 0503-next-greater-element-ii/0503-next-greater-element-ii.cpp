class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&v) {
        stack<int>st;
        int n=v.size();
        vector<int>ans(n, INT_MIN);
        for(int i=0; i<n; ++i){
            while(!st.empty() && v[i]>v[st.top()]){
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; ++i){
            while(!st.empty() && v[i]>v[st.top()]){
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
        for(int&it : ans){
            if(it==INT_MIN){
                it = -1;
            }
        }
        return ans;
    }
};