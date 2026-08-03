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
    ListNode(int x) : val(x), next(NULL) {}
};

/// 找出两个相交链表的相交点
/// 第一种解法：先让其中一个更长的链表走到能使得二者遍历起始位置相同的位置，然后再一起遍历，这样二者就能在相同时刻走到相交节点
/// 再用 == 判断相交即可
/// 计算二者size()差即可得到距离那个位置的长度，然后让更长的链表开始走

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int Asize = 0;
        ListNode* iA = headA;
        while (iA != nullptr)
        {
            iA = iA->next;
            Asize++;
        }

        int Bsize = 0;
        ListNode* iB = headB;
        while (iB != nullptr)
        {
            iB = iB->next;
            Bsize++;
        }

        int minus = abs(Asize - Bsize);
        while (minus > 0)
        {
            if (Asize >= Bsize) headA = headA->next;
            else headB = headB->next;
            minus--;
        }

        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
        
    }
};

/// 第二种解法：双指针跳链法
/// 用两个指针同时遍历A, B，并且两个指针到头时就跳转到对方的头节点上，继续往前遍历
/// 当二者相遇时，正好就是交点
/// 核心：观察可知，二者遍历的总距离都为，自己的总长度+对方链表与相交节点之间的距离，恰好相等
/// 若无相交，则遍历会在二者都是空指针时停下，遍历长度为listA长度+listB长度
/// 保证了算法的正确性

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* iA = headA;
        ListNode* iB = headB;

        while (iA != iB)
        {
            iA = (iA == nullptr) ? headB : iA->next;
            iB = (iB == nullptr) ? headA : iB->next;
        }

        return iA;
    }
};