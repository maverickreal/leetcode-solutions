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
void recoverTree(TreeNode* root) {
    tn*pre=nullptr, *anom1=nullptr, *anom2=nullptr, *cur=root;
    while(cur){
        if(pre!=NULL && pre->val>cur->val){
            if(!anom1){
                anom1=pre;
            }
            anom2=cur;
        }
        if(!(cur->left)){
            pre=cur, cur=cur->right;
            continue;
        }
        tn*rm=cur->left;
        while(rm->right && rm->right!=cur){
            rm=rm->right;
        }
        if(rm->right){
            rm->right=nullptr;
            pre=cur, cur=cur->right;
            continue;
        }
        rm->right=cur;
        cur=cur->left;
    }
    anom1->val+=anom2->val, anom2->val=anom1->val-anom2->val, anom1->val-=anom2->val;
}
};