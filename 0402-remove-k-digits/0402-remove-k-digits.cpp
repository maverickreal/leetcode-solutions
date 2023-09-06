class Solution {
public:
    string removeKdigits(string str, int k) {
        stack<char>st;
        for(char ch : str){
            while(!st.empty() && st.top()>ch && k){
                st.pop();
                --k;
            }
            if(!st.empty() || ch!='0'){
                st.push(ch);
            }
        }
        while(k-- && !st.empty()){
            st.pop();
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return (ans.empty()?"0":ans);
    }
};