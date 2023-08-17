class Solution {
public:
    void func(stack<char>&st, const string&str){
        for(char ch : str){
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
        func(sts, s); func(stt, t);
        return (sts == stt);
    }
};