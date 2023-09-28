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

    ListNode* recur(ListNode* pre, ListNode* now)
    {
        if (now == nullptr)
            return pre;

        ListNode *next = now -> next;
        now -> next = pre;
        return recur(now, next);
    }
    
    ListNode* reverseList(ListNode* head) {
        
        /*
        ListNode *pre = nullptr;
        ListNode *now = head;
        if (head == nullptr || head -> next == nullptr) return now;

        while (now != nullptr)
        {
            ListNode *next = now -> next;
            now -> next = pre;
            pre = now;
            now = next;
        }

        return pre;
        */
        return recur(nullptr, head);
    }
};
