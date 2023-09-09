class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s){
            if(ch!='c'){
                st.push(ch);
                continue;
            }
            if(st.size()<2 || st.top()!='b'){
                return false;
            }
            st.pop();
            if(st.top()!='a'){
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};