class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='('){
                st.push(-1);
            } else{
                int res=0;
                while(st.top()!=-1){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                if(res==0){
                    st.push(1);
                } else{
                    st.push(2*res);
                }
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};