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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return dummy->next;
}
public:
//O(N * K )
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> merged;
            for(int i = 0;i < lists.size();i+=2){
                ListNode* l1= lists[i];
                ListNode* l2 = nullptr;
                if(i + 1 < lists.size()){
                    l2 = lists[i+1];
                }
                merged.push_back(mergeTwoLists(l1,l2));
            }
            lists=merged;
        }
        return lists[0];
    }
};