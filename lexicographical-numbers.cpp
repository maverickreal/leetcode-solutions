class Solution {
public:
    class node {
    public:
        bool word;
        vector<node*>nodes;
        node() {
            word = false;
            nodes.resize(10, nullptr);
        }
    };
    class trie {
    public:
        node* root;
        trie() {
            root = new node();
        }
        void insert(const int& n, node* cur, int num = 0) {
            if(num>n)
                return;
            if (num)
                cur->word = true;
            for (int i = 0;i < 10;++i) {
                int tmp = (num * 10) + i;
                if (tmp) {
                    if (!cur->nodes[i])
                        cur->nodes[i] = new node();
                    insert(n, cur->nodes[i], tmp);
                }
            }
        }
        void search(vector<int>& res, node* nd, int n = 0) {
            if (nd->word)
                res.push_back(n);
            for (short it = 0;it < 10;++it) {
                if (nd->nodes[it] != nullptr)
                    search(res, nd->nodes[it], n * 10 + it);

            }
        }
    };
    vector<int> lexicalOrder(int n) {
        trie tr;
        tr.insert(n, tr.root);
        vector<int>res;
        tr.search(res, tr.root);
        return res;
    }
};