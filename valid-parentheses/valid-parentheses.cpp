class Solution {
public:
    bool isValid(string& s) {
        int o = 0, c = 0, sz = s.length();

        if (!sz)

            return true;

        if (sz & 1 or s[0] == ')' or s[0] == ']' or s[0] == '}')

            return false;

        stack<char> st;

        for (auto it = s.begin(); it != s.end(); ++it)

        {

            if (*it == '(' or *it == '[' or *it == '{')

            {

                o++;

                st.push(*it);

            }

            else if (st.empty() || ((*it == ')' and st.top() != '(') or (*it == ']' and st.top() != '[') or (*it == '}' and st.top() != '{')))

                return false;

            else

            {

                ++c;

                st.pop();

            }

        }

        return o==c;
    }
};