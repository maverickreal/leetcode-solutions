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
    #define tn TreeNode
public:
    void flatten(TreeNode* root) {
    tn* cur = root;
    while (cur) {
        //cout<<cur->val<<' ';
        if (cur->left) {
            tn* rMost = cur->left;
            while (rMost->right && rMost->right != cur)
                rMost= rMost->right;
            if (!rMost->right) {
                rMost->right = cur;
                cur = cur->left;
            }
            else {
                tn* tmp=cur->right;
                cur->right=cur->left;
                cur->left = nullptr;
                rMost->right=tmp;
                cur = tmp;
            }
        }
        else
            cur = cur->right;
    }
  }
};