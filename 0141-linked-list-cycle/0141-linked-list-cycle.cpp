/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool hasCycle(ListNode *head) {
        
        while (head != nullptr)
        {
            if (head -> val == -INT32_MAX) return true;
            head -> val = -INT32_MAX;
            head = head -> next;
        }
        return false;
    }
};