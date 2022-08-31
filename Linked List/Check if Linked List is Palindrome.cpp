/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head || !head->next) {
            return true;
        }
        
        stack<int> st;
        
        Node *slow = head, *fast = head;
        st.push(head->data);
        
        while(fast && fast->next) {
            fast = fast->next->next;
            if(fast) { 
                slow = slow->next;
                st.push(slow->data);        
            }
        }
        
        if(fast) st.pop();
        
        slow = slow->next;
        while(slow) {
            if(st.top() == slow->data) {
                st.pop();
                slow = slow->next;
            } else {
                return false;
            }
        }
        
        if(st.empty()) return true;
        else return false;
        
    }
};