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
#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    unordered_map<Node*, int> m;
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL) return;
        
        Node* temp = head;
        this->m[temp]++;
        while(temp->next) {
            if(this->m[temp->next] > 0) {
                temp->next = NULL;
                break;
            }
            
            temp = temp->next;
            this->m[temp]++;
        }
    }
};