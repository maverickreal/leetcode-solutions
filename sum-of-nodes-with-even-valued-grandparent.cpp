class Solution {
public:
#define tn TreeNode
    int sumEvenGrandparent(TreeNode* rt) {
        if (!rt)
            return 0;
        int sum = sumEvenGrandparent(rt->left) + sumEvenGrandparent(rt->right);
        if (!(rt->val & 1)) {
            if (rt->left) {
                if (rt->left->left)
                    sum += rt->left->left->val;
                if (rt->left->right)
                    sum += rt->left->right->val;
            }
            if (rt->right) {
                if (rt->right->left)
                    sum += rt->right->left->val;
                if (rt->right->right)
                    sum += rt->right->right->val;
            }
        }
        return sum;
    }
};