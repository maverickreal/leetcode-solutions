class Solution {
public:
    typedef long long ll;
#define tn TreeNode
    void func(tn* nd1, tn* nd2) {
        if (!nd2 || nd1 == nd2) return;
        if (!nd1->left)
            nd1->left = nd2->left;
        else if (nd2->left)
            nd1->left->val += nd2->left->val;
        if (!nd1->right)
            nd1->right = nd2->right;
        else if (nd2->right)
            nd1->right->val += nd2->right->val;
        func(nd1->left, nd2->left), func(nd1->right, nd2->right);
    }
    TreeNode* mergeTrees(TreeNode* nd1, TreeNode* nd2) {
        if (!nd1)return nd2;
        if (!nd2)return nd1;
        nd1->val+=nd2->val;
        func(nd1, nd2);
        return nd1;
    }
};