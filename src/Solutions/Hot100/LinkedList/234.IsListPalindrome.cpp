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

/// 先反转后半段链表，再双指针遍历判断
class Solution {
public:
    /// 迭代版没有额外空间复杂度，最好用迭代而非递归
    ListNode* ReverseLinkedList(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;

            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {   
        // 先拿到中点
        int listSize = 0;
        for (ListNode* i = head; i != nullptr; i = i->next, listSize++) {}

        // 最好从中间偏右索引开始反转和判断，逻辑更顺
        int halfIndex = listSize / 2;
        int cnt = 0;

        // 反转中点之后的链表,并且拿到反转后链表的头节点
        ListNode* cur = head;
        for (;cnt < halfIndex;cur = cur->next, cnt++) {}
        ListNode* tail = ReverseLinkedList(cur);

        // 双指针从前后遍历判定
        cnt = 0;
        for (ListNode* i = head, *j = tail; cnt < halfIndex; ++cnt, i = i->next, j = j->next)
        {
            if (i->val != j->val) return false;
        }

        return true;
    }
};