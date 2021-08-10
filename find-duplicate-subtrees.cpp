class Solution {
	#define tn TreeNode
public:
	unordered_map<string,int>ump;
	vector<tn*>res;
	string  func(tn*rt){
		string s="";
		if(!rt)
			return s;
		s.append(to_string(rt->val)+","+func(rt->left)+","+func(rt->right));
		++ump[s];
		if(ump[s]==2)
			res.push_back(rt);
		return s;
	}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* rt) {
        func(rt);
        return res;
    }
};
