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
    vector<int> inorderTraversal(TreeNode* root) {
       TreeNode*nd=root;
        vector<int>res;
        while(nd){
            if(!nd->left){
                res.push_back(nd->val);
                nd=nd->right;
            }
            else{
                TreeNode*check=nd->left;
                while(check->right && check->right!=nd){
                    check=check->right;
                }
                if(check->right){
                    check->right=nullptr;
                    res.push_back(nd->val);
                    nd=nd->right;
                }
                else{
                    check->right=nd;
                    nd=nd->left;
                }
            }
        }
        return res;
    }
};