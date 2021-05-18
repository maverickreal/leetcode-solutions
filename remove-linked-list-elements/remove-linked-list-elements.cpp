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
    ListNode* removeElements(ListNode* head, int val) {
        	if (head == NULL)

		return head;

	while (head->val == val){
        if(head->next==NULL){
            head=NULL;
            return head;
            }
		head = head->next;
        }
	auto i = head;

	while (i->next != NULL)

	{

		if (i->next->val == val)

			i->next = i->next->next;

		else

			i = i->next;

	}

	return head;
    }
};