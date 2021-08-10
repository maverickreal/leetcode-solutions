class Solution {
    class node {
    public:
        bool word;
        vector<node*>nodes;
        node() {
            word = false;
            nodes.resize(27, nullptr);
        }
    };
    class trie {
    public:
        node* root;
        trie() {
            root = new node();
        }
        void insert(const string& s) {
            node* cur = root;
            for (const char& c : s) {
                if (cur->nodes[c - 'a'] == nullptr)
                    cur->nodes[c - 'a'] = new node();
                cur = cur->nodes[c - 'a'];
            }
            cur->word = true;
        }
    };
public:
    string replaceWords(vector<string>& v, string& s) {
        s.push_back(' ');
        trie tr;
        for (auto& it : v)
            tr.insert(it);
        string res, tmp;
        for (int i = 0;i < s.length();++i) {
            if (s[i] == ' ') {
                node* nd = tr.root;
                tmp.push_back('z' + 1);
                for (int j = 0;j < tmp.length();++j) {
                    if (nd->word) {
                        res.append(tmp.substr(0, j));
                        if(res.back()=='{')
                        res.pop_back();
                        break;
                    }

                    if (!nd->nodes[tmp[j] - 'a']) {
                        res.append(tmp);
                        if(res.back()=='{')
                        res.pop_back();
                        break;
                    }

                    nd = nd->nodes[tmp[j] - 'a'];
                }
                tmp.clear();
                res.push_back(' ');
            }
            else
                tmp.push_back(s[i]);
        }
        while (!res.empty() && res.back() == ' ')
            res.pop_back();
        return res;
    }
};
