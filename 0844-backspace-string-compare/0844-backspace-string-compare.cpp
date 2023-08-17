class Solution {
public:
    void operate(stack<char>&st, const string&str){
        for(char ch : str){
            if(ch!='#'){
                st.push(ch);
            } else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<char>sts, stt;
        operate(sts, s); operate(stt, t);
        return (sts == stt);
    }
};