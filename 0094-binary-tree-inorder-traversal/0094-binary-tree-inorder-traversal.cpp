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
vector<int> inorderTraversal(TreeNode* root) {
    tn* nd=root;
    vi(int)ans;
    while(nd){
        if(!nd->left){
            ans.pb(nd->val);
            nd=nd->right;
            continue;
        }
        tn*rm=nd->left;
        while(rm->right && rm->right!=nd){
            rm=rm->right;
        }
        if(rm->right){
            rm->right=nullptr;
            ans.pb(nd->val);
            nd=nd->right;
            continue;
        }
        rm->right=nd;
        nd=nd->left;
    }
    return ans;
}
};