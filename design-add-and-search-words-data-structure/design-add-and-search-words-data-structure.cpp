class WordDictionary {
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
        bool search(node* nd, string& s, int i = 0) {
            if(!nd)
                return false;
            if (i == s.length())
                return nd->word;
            if (s[i] == '.') {
                for (int j = 0;j < 26;++j) {
                    if (nd->nodes[j] && search(nd->nodes[j], s, i + 1))
                        return true;
                }
                return false;
            }
            return search(nd->nodes[s[i] - 'a'], s, i + 1);
        }
    };
    trie tr;
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(string s) {
        tr.insert(s);
    }

    bool search(string s) {
        return tr.search(tr.root, s);
    }
};