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
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

#define ln ListNode

void reverse(ln*nd){
    ln*pre=nullptr;
    while(nd!=nullptr){
        ln*nxt=nd->next;
        nd->next=pre;
        pre=nd, nd=nxt;
    }
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ln *lPre, *rNxt, *l=head, *ret=head, *r=nullptr;
    for(ll i=0;i<right-left+1;++i){
        r=r?r->next:head;
    }
    for(ll i=1;i<left;++i){
        lPre=l, l=l->next, r=r->next;
    }
    rNxt=r->next;
    r->next=nullptr;
    reverse(l);
    // cout<<"l: "<<l->val<<" r: "<<r->val<<nl;
    // if(lPre){
    //     cout<<"lPre: "<<lPre->val<<nl;
    // }
    // if(rNxt){
    //     cout<<"rNxt: "<<rNxt->val<<nl;
    // }
    if(lPre){
        lPre->next=r;
    }
    else{
        ret=r;
    }
    l->next=rNxt;
    return ret;
}
};