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
    bool isPalindrome(ListNode* head) {
        	if (head == NULL or head->next == NULL)

		return true;

	if (head->next->next == NULL)

		return (head->val == head->next->val);

	if (head->next->next->next == NULL)

		return (head->val == head->next->next->val);

	vector<ListNode *> v;

	auto it = head;

	while (it != NULL)

	{

		v.push_back(it);

		it = it->next;

	}

	int i = 0, j = v.size() - 1;

	while (i < j)

	{

		if (v[i]->val != v[j]->val)

			return false;

		++i;

		--j;

	}

	return true;
    }
};