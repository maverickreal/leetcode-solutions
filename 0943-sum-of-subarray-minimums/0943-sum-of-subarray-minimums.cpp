class Solution {
public:
    int sumSubarrayMins(vector<int>&v) {
        int n = v.size(), mod = 1e9 + 7;
        stack<int>st;
        vector<int>pse(n, -1);
        for(int i=n-1; i>-1; --i){
            while(!st.empty() && v[i]<=v[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int>prefix = v;
        int ans = 0;
        for(int i=0 ;i<n; ++i){
            prefix[i] = (((i-pse[i]-1) * v[i]) + prefix[i]) % mod;
            if(pse[i]>-1){
                prefix[i] = (prefix[pse[i]] + prefix[i]) % mod;
            }
            ans = (ans + prefix[i]) % mod;
        }
        return ans;
    }
};