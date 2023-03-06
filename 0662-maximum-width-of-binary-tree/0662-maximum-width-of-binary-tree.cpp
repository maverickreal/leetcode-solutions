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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        list<tuple<TreeNode*, ll>>l={{root, 0}};
        ll ans=1;
        while(!l.empty()){
            ll sz=l.size();
            ans=max(ans, get<1>(l.back())-get<1>(l.front())+1);
            for(ll i=0;i<sz;++i){
                const auto&[nd, id]=l.front();
                if(nd->left){
                    l.push_back({nd->left, 2*id+1});
                }
                if(nd->right){
                    l.push_back({nd->right, 2*id+2});
                }
                l.pop_front();
            }
        }
        return ans;
    }
};