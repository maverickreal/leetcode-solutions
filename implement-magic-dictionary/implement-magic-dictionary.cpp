class MagicDictionary {
public:
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
        int search(node* nd, const string& s, int in = 0, int fl = 0) {
            if (fl > 1)
                return fl;
            if (in == s.length()) {
                if (nd->word)
                    return fl;
                return 2;
            }
            for (int i = 0;i < 26;++i)
                if (nd->nodes[i] && search(nd->nodes[i], s, in + 1, fl + ('a' + i != s[in])) == 1)
                    return 1;
            return 2;
        }
    };
    /** Initialize your data structure here. */
    trie tr;
    MagicDictionary() {

    }

    void buildDict(vector<string> v) {
        for (auto& it : v)
            tr.insert(it);
    }

    bool search(string s) {
        return tr.search(tr.root, s) == 1;
    }
};