class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0, pre=0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='('){
                ++bal;
            } else{
                --bal;
            }
            if(!bal){
                s.erase(begin(s)+pre);
                --i;
                s.erase(begin(s)+i);
                --i;
                pre=i+1;
            }
        }
        return s;
    }
};