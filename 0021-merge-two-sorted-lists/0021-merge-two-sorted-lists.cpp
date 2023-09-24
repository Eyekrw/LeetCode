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

    ListNode* chaining(ListNode* pre, ListNode* l1, ListNode* l2)  // pre는 l2의 pre
    {
        ListNode* tmp = l1;

        tmp = l1 -> next;
        l1 -> next = l2;
        if (pre != nullptr) pre -> next = l1;
        return tmp;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head;

        if (list1 != nullptr && list2 != nullptr)
        {
            if (list1 -> val < list2 -> val) 
                head = list1;
            else
                head = list2;
        }
        else if (list1 == nullptr)
            head = list2;
        else if (list2 == nullptr)
            head = list1;
        else
            return nullptr;

        ListNode* pre1 = nullptr;
        ListNode* pre2 = nullptr;
        ListNode* tmp;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1 -> val < list2 -> val)
            {
                tmp = list1;
                list1 = chaining(pre2, list1, list2);
                pre2 = tmp;
                pre1 = nullptr;
            }
            else
            {
                tmp = list2;
                list2 = chaining(pre1, list2, list1);
                pre1 = tmp;
                pre2 = nullptr;
            }
        }
        return head;
    }
};