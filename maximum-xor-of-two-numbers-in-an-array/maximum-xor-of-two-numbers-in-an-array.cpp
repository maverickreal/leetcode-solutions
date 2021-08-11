class Solution {
public:
    class node {
    public:
        node* z, *o;
        node() {
            z = o = nullptr;
        }
    };
    class trie {
    public:
        node* root;
        trie() {
            root = new node();
        }
        void insert(const int& n) {
            node* cur = root;
            int pos = 32;
            while (pos--) {
                int bit = (1 << pos) & n;
                if (bit) {
                    if (!cur->o)
                        cur->o = new node();
                    cur = cur->o;
                }
                else {
                    if (!cur->z)
                        cur->z = new node();
                    cur = cur->z;
                }
            }
        }
        int search(node* nd, int n) {
            node* cur = root;
            int pos = 32;
            int res = 0;
            while (pos--) {
                int bit = (1 << pos) & n;
                if (bit) {
                    if (cur->o) {
                        res |= (1 << pos);
                        cur = cur->o;
                    }
                    else
                        cur = cur->z;
                }
                else {
                    if (cur->z)
                        cur = cur->z;
                    else {
                        res |= (1 << pos);
                        cur = cur->o;
                    }
                }
            }
            return res;
        }
    };
    int findMaximumXOR(vector<int>& v) {
        trie tr;
        for (int& i : v)
            tr.insert(i);
        int res = 0;
        for (int& i : v)
            res = max(res, tr.search(tr.root, i ^ INT_MAX) ^ i);
        return res;
    }
};