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

/// 第一种，迭代法
/// 随着头指针向尾部迭代，每次都把当前节点指向上一个节点
/// 核心是先保存下一个节点的状态，再重定向

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;

        while (head != nullptr)
        {
            // 保存下个节点状态
            ListNode* next = head->next;

            head->next = prev;
            prev = head;
            head = next;
        }

        return prev; // head 向前指向反转前链表的最后一个null，prev向后，作为反转后链表的第一个节点
    }
};

/// 第二种，递归法
/// 假设后面的链表全部反转完毕了，处理当前节点的反转关系即可
/// 中止条件：head 一直深入到最后一个节点，相当于 nullptr 单独反转完毕，从最后一个元素->nullptr 开始反转
/// 每一个递归层里，head都是独立的局部指针变量，因此它就对应于递归时那个时刻的自己，而不会被递归状态改变
/// 因此，每次递归的内部处理，head 总是指向“当前正在处理的反转链表对应的要反转的链表头”
/// 这就是为什么它要让下一个节点的 next 指向自己，然后断掉自己的next
/// 这里的 newHead 代表真正被反转完毕的链表的链表头，与假设对应，因此返回的是它

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // 先反转 head 后面的链表，
        // newHead 是反转后整段链表的新头，保存它，它应该一直不变
        ListNode* newHead = reverseList(head->next);

        head->next->next = head; // 反转后链表的尾元素指向自己
        
        // 断开当前节点原来指向后继节点的连接，
        // 当前节点成为反转后链表的尾节点
        head->next = nullptr; 

        return newHead;
    }
};