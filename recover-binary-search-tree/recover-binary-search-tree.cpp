class Solution {
#define tn TreeNode
public:
    void recoverTree(TreeNode* root) {
        tn* cur = root, * a = nullptr, * b = nullptr, * prev = nullptr;
        while (cur) {
            if (cur->left) {
                //tn* rMost = getFarRight(cur->left, cur);
                tn* rMost = cur->left;
                while (rMost->right && rMost->right != cur)
                    rMost = rMost->right;
                if (rMost->right) {
                    if (prev->val > cur->val) {
                        if (!a)
                            a = prev;
                        b = cur;
                    }
                    rMost->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
                else {
                    rMost->right = cur;
                    cur = cur->left;
                }
            }
            else {
                if (prev && prev->val > cur->val) {
                    if (!a)
                        a = prev;
                    b = cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        if (a) {
            a->val += b->val;
            b->val = a->val - b->val;
            a->val -= b->val;
        }
    }
};