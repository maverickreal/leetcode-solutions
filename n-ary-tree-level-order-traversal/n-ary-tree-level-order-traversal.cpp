class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        if(!root)
            return res;
        while (!q.empty()) {
            vector<int>tmp(q.size());
            for (int i = 0;i < tmp.size();++i) {
                auto it = q.front();
                q.pop();
                tmp[i] = it->val;
                for (auto ti : it->children)
                    q.push(ti);
            }
            res.push_back(tmp);
        }
        return res;
    }
};