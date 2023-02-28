//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

bool swap(Node*a, Node*b){
    ll firstDif=-1;
    while(a!=nullptr && b!=nullptr){
        if(firstDif==-1 && a->data!=b->data){
            firstDif=b->data>a->data;
        }
        a=a->next, b=b->next;
    }
    if(a!=nullptr || b!=nullptr){
        return (b!=nullptr);
    }
    return firstDif;
}

Node*reverse(Node*nd){
    Node*pre=nullptr;
    while(nd!=nullptr){
        Node*nxt=nd->next;
        nd->next=pre;
        pre=nd, nd=nxt;
    }
    return pre;
}

Node*trim(Node*nd){
    while(nd!=nullptr && nd->data==0){
        nd=nd->next;
    }
    return (nd==nullptr?new Node(0):nd);
}

Node* subLinkedList(Node* a, Node* b){
    a=trim(a), b=trim(b);
    if(swap(a, b)){
        Node*tmp=a;
        a=b, b=tmp;
    }
    a=reverse(a), b=reverse(b);
    bool bor=0;
    Node*aHead=a;
    while(a!=nullptr){
        if(bor){
            if(a->data>0){
                a->data-=1, bor=0;
            }
            else{
                a->data=9;
            }
        }
        ll bVal=b!=nullptr?b->data:0;
        if(a->data>=bVal){
            a->data-=bVal;
        }
        else{
            bor=1;
            a->data = 10 + a->data - bVal;
        }
        // cout<<a->data<<' ';
        // if(b!=nullptr){
        //     cout<<b->data<<' ';
        // }
        // cout<<nl;
        a=a->next;
        if(b!=nullptr){
            b=b->next;
        }
    }
    aHead=reverse(aHead);
    return trim(aHead);
}