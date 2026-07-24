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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;  if (!head || !head->next || k == 0) return head;
        int length = 1;
        ListNode* oldTail = head;
        while(oldTail->next){
            oldTail = oldTail->next;
            length++;
        }
        k %=length;
         if (k == 0) return head;
        oldTail->next = head;
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;

    }
};