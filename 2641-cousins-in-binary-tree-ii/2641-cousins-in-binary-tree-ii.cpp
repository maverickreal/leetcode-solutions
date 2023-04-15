class Solution{
    typedef TreeNode tn;
public:
    void bfs(tn*rt){
        rt->val=0;
        list<tn*>l={rt}; // transformed parents
        while(!l.empty()){
            int sum=0; // sum of the all nodes at the currentl depth
            for(tn* par : l){
                if(par->left){
                    sum+=par->left->val;
                }
                if(par->right){
                    sum+=par->right->val;
                }
            }
            int sz=l.size();
            while(sz--){
                tn* par = l.front();
                l.pop_front();
                int lc = (par->left ? par->left->val : 0),
                    rc = (par->right ? par->right->val : 0);
                if(par->left){
                    par->left->val=sum-lc-rc;
                    l.push_back(par->left);
                }
                if(par->right){
                    par->right->val=sum-lc-rc;
                    l.push_back(par->right);
                }
            }
        }
    }
    tn* replaceValueInTree(tn* root) {
        bfs(root);
        return root;
    }
};