class Solution {
public:
    string decodeString(string& s) {
        stack<char>st1, st2;
        string res;
        int sz = s.length();
        for (int i = 0;i < sz;++i) {
            const char& ch = s[i];
            if (ch >= '0' && ch <= '9') {
                int j = i - 1;
                while (++j < sz && s[j] >= '0' && s[j] <= '9');
                int num = stoi(s.substr(i, j - i));
                st1.push(num);
                st2.push('[');
                i = j;
            }
            else if (ch == ']') {
                string tmp;
                while (st2.top() != '[') {
                    tmp.push_back(st2.top());
                    st2.pop();
                }
                st2.pop();
                reverse(tmp.begin(), tmp.end());
                while (st1.top()--)
                    for (char& c : tmp)
                        st2.push(c);
                st1.pop();
            }
            else
                st2.push(ch);
        }
        while(!st2.empty()){
            res.push_back(st2.top());
            st2.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};