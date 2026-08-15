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

/// 双指针，哪个小就加入并后移，另一个不动
/// 使用 dummy 哑节点省去 ans == nullptr 特判
/// 不建空节点，直接复用链表中的节点
/// 最后,一条链表走到空时直接接入另一个链表的后续部分

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode dummy;
        ListNode* cur = &dummy;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1-> val <= p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
            } else
            {
                cur->next = p2;
                p2 = p2->next;
            }

            cur = cur->next;
        }

        cur->next = p1 != nullptr ? p1 : p2;

        return dummy.next;
    }
};