class Solution {
public:
    char getOpen(char ch){
        if(ch==')'){
            return '(';
        }
        if(ch==']'){
            return '[';
        }
        return '{';
    }
    bool isValid(string s) {
        int sz = s.size();
        stack<char>st;
        for(int i=0; i<sz; ++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty() || st.top()!=getOpen(s[i])){
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};