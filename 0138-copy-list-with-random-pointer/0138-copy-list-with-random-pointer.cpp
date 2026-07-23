/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* curr = head;
        while(curr != nullptr){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next; 
        }
        curr = head;
        while(curr !=nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* cloneHead = head->next;
        while(curr != nullptr){
            Node* clone = curr->next;
            curr->next= clone->next;
            if(clone->next != nullptr){
                clone->next = clone->next->next;
            }
            curr=curr->next;
        }
        return cloneHead;
    }
};