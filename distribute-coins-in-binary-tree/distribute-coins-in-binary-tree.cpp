class Solution {
public:
	int res=0;
	#define tn TreeNode
	int func(tn*rt,int coins=0){
		if(!rt)
			return 0;
		int a=func(rt->left,coins),b=func(rt->right,coins);
		res+=abs(a)+abs(b);
		return a+b+rt->val-1;
	}
    int distributeCoins(TreeNode* rt) {
        func(rt);
        return res;
    }
};