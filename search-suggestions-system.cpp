class Solution {
private:
    class node {
    public:
        bool word;
        vector<node*>nodes;
        node() {
            word = false;
            nodes.resize(26, nullptr);
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
        void search(vector<string>& v, node* nd, string s) {
            if (v.size() == 3 || nd == nullptr)
                return;
            if (nd->word)
                v.push_back(s);
            for (short it = 0;it < 26;++it) {
                if (nd->nodes[it] != nullptr) {
                    s.push_back('a' + it);
                    search(v, nd->nodes[it], s);
                    s.pop_back();
                }
            }
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& v, string& s) {
        trie tr;
        for (auto& it : v)
            tr.insert(it);
        vector<vector<string>>res;
        string pre = "";
        node* nd = tr.root;
        for (char& ch : s) {
            if (nd == nullptr) {
                res.push_back({});
                continue;;
            }
            nd = nd->nodes[ch - 'a'];
            pre.push_back(ch);
            vector<string>tmp;
            tr.search(tmp, nd, pre);
            res.push_back(tmp);
        }
        return res;
    }
};