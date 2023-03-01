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
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
#define tn TreeNode
tn* root=nullptr;
int minCameraCover(TreeNode*nd) {
    if(!nd){
        return 0;
    }
    if(root==nullptr){
        root=nd;
    }
    if(!nd->left && !nd->right){
        if(nd==root){
            nd->val=2;
            return 1;
        }
        return 0;
    }
    ll ans=minCameraCover(nd->left)+minCameraCover(nd->right);
    bool put=(nd->left && nd->left->val==0) || (nd->right && nd->right->val==0);
    if(put){
        nd->val=2;
        return ans+1;
    }
    bool dont=(nd->left && nd->left->val==2) || (nd->right && nd->right->val==2);
    if(dont){
        nd->val=1;
        return ans;
    }
    if(nd==root){
        nd->val=2;
        return ans+1;
    }
    return ans;
}
};