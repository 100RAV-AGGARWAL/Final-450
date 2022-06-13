#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;

	Node(int data) {
		this->data;
		next = NULL;
	}
};

struct LinkedList {
	Node *head;

	LinkedList() { head = NULL; }

	void reverseiteratively() {
		Node *curr = head, *pre = NULL, *next = NULL;

		while(curr != NULL) {
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr=next; 
		}
		head = pre;
	}

	void reverseRecursively() {
		
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--) {
		
	}

	return 0;
}