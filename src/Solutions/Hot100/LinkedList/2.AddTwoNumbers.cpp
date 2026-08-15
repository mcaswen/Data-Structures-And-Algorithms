#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// 把是否进位当作一个全局状态来维护即可

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy;
        ListNode* curNode = &dummy;

        bool nextAdd1 = false;

        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode* newNode = new ListNode();
            int cur = 0;

            if (l1 != nullptr && l2 != nullptr)
            {
                cur = l1->val + l2->val + (nextAdd1 ? 1 : 0);
                l1 = l1->next;
                l2 = l2->next;
            }
            
            else if (l1 == nullptr && l2 != nullptr)
            {
                cur = l2->val + (nextAdd1 ? 1 : 0);
                l2 = l2->next;
            } 

            else if (l1 != nullptr && l2 == nullptr)
            {
                cur = l1->val + (nextAdd1 ? 1 : 0);
                l1 = l1->next;
            } 

            if (cur >= 10)
            {
                cur -= 10;
                nextAdd1 = true;
            } else nextAdd1 = false;

            newNode->val = cur;
            curNode->next = newNode;
            curNode = curNode->next;
        }
        
        if (nextAdd1)
        {
            ListNode* newNode = new ListNode();
            newNode->val = 1;
            curNode->next = newNode;
        }


        return dummy.next;
    }
};