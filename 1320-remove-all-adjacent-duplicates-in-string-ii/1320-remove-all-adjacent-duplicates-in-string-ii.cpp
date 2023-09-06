class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(int i=0; i<s.size(); ++i){
            if(st.empty() || s[i]!=st.top().first){
                st.push({s[i], 1});
            } else{
                ++st.top().second;
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            while(st.top().second--){
                ans.push_back(st.top().first);
            }
            st.pop();
        }
        return string(rbegin(ans), rend(ans));
    }
};