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
    void func(TreeNode*nd){
        if(!nd)
            return;
        auto tmp=nd->left;
        nd->left=nd->right;
        nd->right=tmp;
        func(nd->left),func(nd->right);
    }
    TreeNode* invertTree(TreeNode* nd) {
        func(nd);
        return nd;
    }
};