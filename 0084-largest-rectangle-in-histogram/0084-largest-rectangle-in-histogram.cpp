class Solution {
public:
    int largestRectangleArea(const vector<int>&h) {
        int n=h.size();
        vector<int>pse(n, -1), nse(n, n);
        stack<int>st;
        for(int i=0; i<n; ++i){
            while(!st.empty() && h[st.top()]>h[i]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>-1; --i){
            while(!st.empty() && h[i]<h[st.top()]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            int beg = pse[i], end = nse[i];
            // cout<<i<<' '<<beg<<' '<<end<<endl;
            ans = max(ans, (end-beg-1) * h[i]);
        }
        return ans;
    }
};