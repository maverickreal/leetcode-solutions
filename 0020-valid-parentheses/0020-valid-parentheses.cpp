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
        stack<char>st;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            } else{
               if(!st.empty() && st.top()==getOpen(s[i])){
                   st.pop();
               }else{
                   return false;
               }
            }
        }
        return st.empty();
    }
};