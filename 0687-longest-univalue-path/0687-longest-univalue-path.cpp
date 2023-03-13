class Solution {
public:
    typedef TreeNode tn;

    int ans;

    int func(tn*nd){
        int left=0, right=0;
        if(nd->left){
            int leftAns=func(nd->left);
            if(nd->left->val==nd->val){
                left=leftAns+1;
            }
        }
        if(nd->right){
            int rightAns=func(nd->right);
            if(nd->right->val==nd->val){
                right=rightAns+1;
            }
        }
        ans=max(ans, left+right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root){
        ans=0;
        if(root){
            func(root);
        }
        return ans;
    }
};