class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(char ch : s){
            if(st.empty() || st.top().first!=ch){
                st.push({ch, 1});
            } else{
                ++st.top().second;
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()){
            while(st.top().second--){
                ans.push_back(st.top().first);
            }
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};