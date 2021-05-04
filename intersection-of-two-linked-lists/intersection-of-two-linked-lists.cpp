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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2){
    if(l1==NULL or l2==NULL)
        return NULL;
    if(l1->next==l2 or l2->next==l1)
        return (l1->next==l2?l2:l1);
	if (l1 == l2)

		return l2;

	ListNode *i = l1, *j = l2;

	while (true)

	{

		if (i == j)
			return i;
		if (i->next == NULL and j->next==NULL)
            break;
        if(i->next==NULL)
			i = l2;
		else
			i = i->next;
		if (j->next==NULL)
			j = l1;
		else
			j = j->next;
	}
	return NULL;
    }
};