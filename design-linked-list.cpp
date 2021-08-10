class MyLinkedList {
  class node{
  public:
    int val;
    node*prev,*next;
    node(int n=0){
      prev=nullptr,next=nullptr;
      val=n;
    }
  };
public:
  node *hd,*tl;
  int sz;
    /** Initialize your data structure here. */
    MyLinkedList() {
        hd=nullptr,tl=nullptr;
        sz=0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int in) {
        if(in>=sz)
          return -1;
        node*it=hd;
        while(in--)
          it=it->next;
        return it->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int n) {
      node*nd=new node(n);
      nd->next=hd;
      if(hd)
        hd->prev=nd;
      hd=nd;
      if(!sz)
        tl=nd;
      ++sz;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int n) {
      node*nd=new node(n);
      nd->prev=tl;
      if(tl)
        tl->next=nd;
      tl=nd;
      if(!sz)
        hd=nd;
      ++sz;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int in, int n) {
        if(in>sz)
          return;
        if(in==sz || !sz)
          return addAtTail(n);
        if(!in)
          return addAtHead(n);
        ++sz;
        node *pre,*it=hd,*nd=new node(n);
        while(in--)
          it=it->next;
        pre=it->prev;
        if(pre)
          pre->next=nd;
        nd->prev=pre;
        nd->next=it;
        it->prev=nd;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int in) {
      if(in>=sz)
        return;
      if(sz==1){
        sz=0;
        hd=nullptr,tl=nullptr;
        return;
      }
      node *pre,*nxt,*it=hd;
      for(int x=0;x<in;++x)
        it=it->next;
      pre=it->prev;
      nxt=it->next;
      if(pre)
        pre->next=nxt;
      if(nxt)
        nxt->prev=pre;
      it->next=nullptr;
      it->prev=nullptr;
      if(!in)
        hd=nxt;
      if(in==sz-1)
        tl=pre;
      --sz;
    }
};