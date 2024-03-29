/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd Cycle Detection // tortoise and hare algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(!(slow->next) && !(fast) &&!(fast->next)){
          slow=slow->next;
          fast=fast->next->next;
      
          if(slow==fast) return true;
        }

        return false;
    }
};
