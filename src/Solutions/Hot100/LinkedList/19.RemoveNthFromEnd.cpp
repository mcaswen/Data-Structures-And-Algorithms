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

// 先找到整个链表的大小，size - n 就是要删除的节点索引(0base)
// 然后找到前一个节点也就是size - n - 1, 直接连接上size - n + 1即可(若==nullptr则说明要删除的是最后一个节点，那么就连接nullptr)
// 注意若 size - n - 1 小于 0，说明要删除的是第一个节点，直接返回 head->next 即可
// 如果要一次扫描，那就把链表存入一个数组，然后通过索引从数组里取出即可

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<ListNode*> nodes;

        ListNode* cur = head;
        while (cur != nullptr)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }
        
        int size = nodes.size();
        if (size - n - 1 < 0) return head->next; // 节点数量保证大于等于 1

        ListNode* prev = nodes[size - n - 1];
        if (prev->next->next != nullptr)
        {
            prev->next = prev->next->next;
        } else prev->next = nullptr;

        return head;
    }
};

/// O1空间做法：快慢指针，在head之前构造一个dummy，然后让快慢指针一起从dummy出发，慢指针比快指针慢n+1个节点
/// 这样快指针遇到nullptr时，慢指针就会停在要删除的节点的前一个节点，按照连接规则连接即可

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode dummy;
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        int cnt = n + 1;

        while (fast != nullptr)
        {
            fast = fast->next;
            if (cnt <= 0) slow = slow->next;
            cnt--;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};