//{ Driver Code Starts
// driver code

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node *sortedDll(Node *head, int k)
    {
        // Write your code here
    //in the first k node have the smallest node => use priority queue to push all the node in min heap order
        //declare a minheap priority queue
        auto compare = [](Node* a, Node* b)->bool{
            return a->data > b->data;
        };
        priority_queue<Node*, vector<Node*>,decltype(compare)> pq(compare);
        Node* newHead = nullptr;
        Node* last;
        int cnt = 0;
        while(head!=nullptr && cnt <= k){
            pq.push(head);
            head = head->next;
            k++;
        }
        while(!pq.empty()){
            if(newHead == nullptr){
                newHead = pq.top();
                pq.pop();
                newHead->prev = nullptr;
                last = newHead;
            }
            else{
                pq.push(head);
                head = head->next;
                last->next = pq.top();
                last->next->prev = last;
                last = last->next;
                pq.pop();
            }
            if(head == nullptr) break;
            
        }
        //avoid loop from 2 last node 
        last->next == nullptr;
        return newHead;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        head = ob.sortedDll(head,pos);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends