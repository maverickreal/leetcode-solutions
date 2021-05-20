class Solution {
    unordered_set<string>ust;
    const string letters = "ABCDEFG";
    bool func(const string& s, list<char>l = {}, int i = 0) {
        /* if (!i)
            cout << s << '\n';
        for (const char& ch : l)
            cout << ch << ' ';
        cout << i << '\n'; */
        if (s.length() == 1)
            return true;
        if (i == s.length() - 1)
            return func(string(l.begin(), l.end()));
        if (i >= s.length())
            i = 0;
        string abc = s.substr(i, 2);
        for (const char& ch : letters) {
            abc.push_back(ch);
            if (ust.find(abc) != ust.end()) {
                l.push_back(ch);
                if (func(s, l, i + 1))
                    return true;
                l.pop_back();
            }
            abc.pop_back();
        }
        return false;
    }
public:
    bool pyramidTransition(string& s, vector<string>& v) {
        if (v.empty())
            return s.length() == 1;
        ust = unordered_set<string>(v.begin(), v.end());
        return func(s);
    }
};