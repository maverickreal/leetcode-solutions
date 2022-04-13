/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class cmp{
        public:
        bool operator()(ListNode*x, ListNode*y){
            return x->val>y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>&v) {
        ListNode*res=new ListNode(), *cur=res;
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;
        int sz=v.size();
        while(true){
            bool fl=false;
            for(auto&it:v){
                if(it){
                    fl=true;
                    pq.push(new ListNode(it->val));
                    it=it->next;
                }
            }
            if(!fl)
                break;
        }
        while(!pq.empty()){
            cur->next=pq.top();
            pq.pop();
            cur=cur->next;
        }
        return res->next;
    }
};