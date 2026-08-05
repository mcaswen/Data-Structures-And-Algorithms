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

/// 若有环，快慢指针会相遇
/// 同时把快指针移动到起点，和慢指针都和1步长前进，相遇时即是入环节点
/// 若无环，快指针会遇到nullptr

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;

        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }

            if (slow == fast) break;
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
        
    }
};