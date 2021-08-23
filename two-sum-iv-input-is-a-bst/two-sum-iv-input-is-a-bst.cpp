/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#define tn TreeNode
    bool findTarget(TreeNode* rt, int tar) {
        unordered_map<int, int>ump;
        ++ump[rt->val];
        queue<tn*>q;
        q.push(rt);
        while (!q.empty()) {
            tn* nd = q.front();
            q.pop();
            if (nd->left) {
                ++ump[nd->left->val];
                q.push(nd->left);
            }
            if (nd->right) {
                ++ump[nd->right->val];
                q.push(nd->right);
            }
        }
        for (auto& it : ump)
            if (ump.find(tar - it.first) != ump.end() && (tar != (it.first*2) || ump[it.first] > 1))
                return true;
        return false;
    }
};