class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& v) {
        int res = 0;
        unordered_map<char, queue<string>>ump;
        for (char& ch : s)
            ump[ch] = {};
        for (auto& i : v)
            if (ump.find(i.front()) != ump.end())
                ump[i.front()].push(i);
        for (int i = 0;i < s.length();++i) {
            auto& l = ump[s[i]];
            int sz = l.size();
            while (sz--) {
                auto tmp = l.front();
                //cout << tmp << ' ';
                l.pop();
                if (tmp.size() == 1)
                    ++res;
                else if (ump.find(tmp[1]) != ump.end())
                    ump[tmp[1]].push(tmp.substr(1));
            }
        }
        return res;
    }
};