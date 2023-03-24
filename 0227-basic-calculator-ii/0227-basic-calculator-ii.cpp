class Solution {
public:
    bool isNum(char ch){
        return (ch>='0' && ch<='9');
    }

    int calculate(const string& str){
        int sz=str.size();
        list<string>st;
        for(int i=0; i<sz; ++i){
            const char& cur = str[i];
            if(cur==' '){
                continue;
            }
            if(isNum(cur)){
                int j=i;
                while(j+1<sz && isNum(str[j+1])){
                    ++j;
                }
                int num=stoi(str.substr(i, j-i+1));
                i=j;
                if(!st.empty() && (st.back()=="*" || st.back()=="/")){
                    string op = st.back();
                    st.pop_back();
                    int num2 = stoi(st.back());
                    st.back() = to_string(op == "*" ? num*num2 : num2/num);
                }
                else{
                    st.push_back(to_string(num));
                }
                continue;
            }
            st.push_back("");
            st.back().push_back(cur);
        }
        while(st.size()>1){
            int num=stoi(st.front());
            st.pop_front();
            string op=st.front();
            st.pop_front();
            int num2=stoi(st.front());
            st.front() = to_string(op=="+" ? num+num2 : num-num2);
        }
        return stoi(st.front());
    }
};