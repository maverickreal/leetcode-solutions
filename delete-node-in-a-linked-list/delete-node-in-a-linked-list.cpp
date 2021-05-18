/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* head) {
        	if (head->next->next == NULL)

	{

		head->val = head->next->val;

		head->next = NULL;

		return;

	}

	ListNode* it = head;

	while (it->next != NULL)

	{

		it->val = it->next->val;

		if (it->next->next == NULL)

		{

			it->next = NULL;

			return;

		}

		it = it->next;
    }
        }
};