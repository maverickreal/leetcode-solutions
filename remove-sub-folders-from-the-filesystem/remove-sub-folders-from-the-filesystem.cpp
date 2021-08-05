class Solution {
    class node {
    public:
        bool word;
        unordered_map<string, node*>ump;
        node() {
            word = false;
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
            string tmp = "";
            for (int i = 1;i < s.length();++i) {
                if (s[i] == '/') {
                    if (cur->ump.find(tmp) == cur->ump.end())
                        cur->ump[tmp] = new node();
                    cur = cur->ump[tmp];
                   // cout<<tmp<<' ';
                    tmp.clear();
                }
                else
                tmp.push_back(s[i]);
            }
            if (!tmp.empty()) {
                if (cur->ump.find(tmp) == cur->ump.end())
                    cur->ump[tmp] = new node();
                cur = cur->ump[tmp];
            }
            cur->word = true;
        }
        void search(vector<string>& v, node* nd, string s = "") {
            if (nd->word) {
                v.push_back(s);
                return;
            }
            for (auto& it : nd->ump) {
                string tmp = s + "/" + it.first;
                search(v, it.second, tmp);
            }
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& f) {
        trie tr;
        for (auto& it : f)
            tr.insert(it);
        vector<string>res;
        tr.search(res, tr.root);
        if (tr.root->word)
            cout << "here ";
        return res;
    }
};