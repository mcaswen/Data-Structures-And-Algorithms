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

/// 注意到前面的节点也要同步接上移动后的节点，所以应该以三个节点为一个单位。
/// 把要处理的三个节点当作一个单独单元处理，每次循环处理 prev,cur 和 next，prev 移动到 cur, 然后 cur 后移一位， 进行下一轮处理
/// 真正交换的是cur和next，顺序可以是cur接next->next，next接cur,prev接next。
/// 当 cur == null || cur->next == null 时停止
/// 初始时 prev 依旧 = dummy

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode dummy;
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur != nullptr && cur->next != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
            cur = cur->next;

        }

        return dummy.next;
    }
};


