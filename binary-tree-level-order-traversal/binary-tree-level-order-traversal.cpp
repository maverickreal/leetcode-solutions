class Solution {
  #define nd TreeNode
public:
    vector<vector<int>> levelOrder(TreeNode* rt) {
        queue<nd*>*q=new queue<nd*>;
        q->push(rt);
        vector<vector<int>>res;
        while(!q->empty()){
          vector<int>tv;
          queue<nd*>*tq=new queue<nd*>;
          while(!q->empty()){
            auto it=q->front();
            q->pop();
            if(!it)
              continue;
            tv.push_back(it->val);
            tq->push(it->left);
            tq->push(it->right);
          }
          
            if(!tv.empty())
                res.push_back(tv);
          q=tq;
        }
        return res;
    }
};