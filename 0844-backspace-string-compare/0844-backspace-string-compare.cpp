class Solution {
public:
    void operate(stack<char>&st, const string&str){
        for(const char&ch : str){
            if(ch=='#'){
                if(!st.empty()){
                    st.pop();
                }
            } else{
                st.push(ch);
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<char>sts, stt;
        operate(sts, s); operate(stt, t);
        return (sts == stt);
    }
};