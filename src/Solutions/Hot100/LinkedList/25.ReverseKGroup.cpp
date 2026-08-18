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

/// 借鉴反转2节点的思路，核心有两个，一是判断剩下的部分是否需要反转，二是内部的反转算法
/// 直接先把要反转的尾部->next保存再置null，用反转链表算法反转整个要反转的部分
/// 再把 prev 接上反转后的起点 start，反转后的终点 end 接上保存的 next
/// 之后就是，prev = end，start = end->next;

class Solution {
public:

    ListNode* findKth(ListNode* start, int k)
    {
        while (start != nullptr && k - 1 > 0)
        {
            start = start->next;
            k--;
        }

        return start;
    }

    pair<ListNode*, ListNode*> Reverse(ListNode* start)
    {
        ListNode* cur = start;
        ListNode* prev = nullptr;

        while (cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        return make_pair(prev, start);
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        ListNode* end = findKth(head, k);

        while (end != nullptr)
        {
            ListNode* next = end->next;
            end->next = nullptr;

            auto [newHead, newTail] =  Reverse(cur);
            cur = newHead; end = newTail;

            prev->next = cur;
            end->next = next;

            cur = next;
            prev = end;

            end = findKth(next, k);
        }

        return dummy.next;
    }
};