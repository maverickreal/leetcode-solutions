class Solution {
public:
    // int stoi(const string&str){
    //     try{
    //         return std::stoi(str);
    //     }
    //     catch(const exception& err){
    //         cout<<'|'<<str<<'|'<<endl;
    //     }
    //     return 0;
    // }
    
    bool isNum(const char& ch){
        return (ch>='0' && ch<='9');
    }
    
    bool isOp(const char& ch){
        return (ch=='+' || ch=='-');
    }

    int calculate(string &str){
        str.push_back(')');
        int sz=str.size();
        stack<string>st;
        st.push("(");
        for(int i=0; i<sz; ++i){
            const char& ch = str[i];
            if(ch==' '){
                continue;
            }
            if(isOp(ch) || ch=='('){
                st.push("");
                st.top().push_back(ch);
                continue;
            }
            if(isNum(ch)){
                if(!st.empty() && isNum(st.top().back())){
                    st.top().push_back(ch);
                }
                else{
                    st.push("");
                    st.top().push_back(ch);
                }
                continue;
            }
            int num=0;
            while(st.top()!="("){
                string cur=st.top();
                st.pop();
                if(cur=="+" || cur=="-"){
                    continue;
                }
                int item = stoi(cur);
                if(!st.empty() && st.top()=="-"){
                    item=-item;
                }
                num+=item;
            }
            st.top() = to_string(num);
        }
        return stoi(st.top());
    }
};