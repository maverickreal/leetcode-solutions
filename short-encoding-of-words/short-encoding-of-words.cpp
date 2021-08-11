class Solution {
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
        int search(node* it) {
            if (!it)
                return 0;
            int tmp = 0;
            for (node* nd : it->nodes)
                tmp = max(tmp, search(nd));
            return 1 + tmp;
        }
        int insert(string& s) {
            reverse(s.begin(), s.end());
            node* cur = root;
            int cnt = 0;
            node* nd = nullptr;
            for (const char& c : s) {
                if (cur->nodes[c - 'a'] == nullptr)
                    cur->nodes[c - 'a'] = new node();
                else {
                    cnt++;
                    nd = cur->nodes[c - 'a'];
                }
                cur = cur->nodes[c - 'a'];
            }
            if (cur->word)
                return -1;
            cur->word = true;
            for (node* it : cur->nodes)
                if (it)
                    return -1;
            if (nd) {
                int tmp = 0;
                for (node* it : nd->nodes) {
                    if (it) {
                        if (!tmp)
                            ++tmp;
                        else {
                            cnt = 0;
                            break;
                        }
                    }
                }
            }
            return s.length() - cnt - (cnt != 0);
        }
    };

    int minimumLengthEncoding(vector<string>& v) {
        int res = 0;
        trie tr;
        for (auto& it : v) {
            int tmp = tr.insert(it);
            res += tmp + 1;
            cout << tmp << ' ';
        }
        return res;
    }
};