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
private:
    int getLength(ListNode* head){
    int length = 0;
    while(head){
        length++;
        head = head->next;
    }
    return length;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int remaining = getLength(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* previousGroup = dummy;
        while(remaining >= k ){
            ListNode* groupStart = previousGroup->next;
            ListNode* curr = groupStart;
            ListNode* prev = nullptr;
            int times = k;
            while(times--){
                ListNode* next = curr->next;
                curr->next = prev;
                prev= curr;
                curr = next;
            }
            previousGroup->next = prev;
            groupStart->next = curr;
            previousGroup = groupStart;
            remaining -= k;
        }
        return dummy->next;
    }
};