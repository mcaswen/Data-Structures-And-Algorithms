#include <vector>
#include <queue>

using namespace std;

void HeapSwap(vector <int>& arr, int a, int b) {

    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t; 

}

//向上调整大根堆
void InsertHeap(vector <int>& heap, int a) {

    heap.push_back(a);
    int i = heap.size() - 1;

    while (heap[i] > heap[(i - 1) / 2]) {

        HeapSwap(heap, i, (i - 1) / 2);
        i = (i - 1) / 2;

    }

}

//向下调整大根堆
//假设插入的数值小于当前节点值
void heapify(vector <int>& arr, int loc, int val, int heapsize) {

    arr[loc] = val;
    int le = loc * 2 + 1;
    int size = heapsize;
    //有左孩子
    while (le < size) { 
        
        int max_child = le + 1 < size && arr[le + 1] > arr[le]? le + 1 : le;
        
        if (arr[max_child] <= arr[loc]) return;//若无法替换左/右孩子，即比左右孩子都大，那么调整结束，直接返回

        HeapSwap(arr, max_child, loc);
        loc = max_child;
        le = loc * 2 + 1;
    
    }

}

//堆排序
void HeapSort(vector <int>& arr) {

    vector <int> heap;
    
    int size = 0;
    for (; size < arr.size(); size++) {

        InsertHeap(heap, arr[size]);

    }

    arr = heap;

    for (; size > 0;) {

        HeapSwap(arr, --size, 0);
        heapify(arr, 0, arr[0], size);

    }

}

//从底到顶建堆，建堆O(n)级
void HeapSort2(vector <int>& arr) {

    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {

        heapify(arr, i, arr[i], n);

    }

    int size = n;

    while (size > 1) {

        HeapSwap(arr, --size, 0);
        heapify(arr, 0, arr[0], size);

    }

}

//合并k个有序链表, O(n * logk)
struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x): val(x), next(nullptr) {}

};

struct Compare {

    bool operator()(ListNode* a, ListNode* b) {

        return a->val > b->val;

    }

};

ListNode* MergeList(vector <ListNode*> HeadList) {

    priority_queue <ListNode*,vector <ListNode*>, Compare> MinHeap;

    for (auto p: HeadList) {

        if (p != nullptr) MinHeap.push(p);

    }
 
    if (MinHeap.empty()) return NULL;

    ListNode* head = MinHeap.top();
    MinHeap.pop();

    ListNode* cur = head;
    if (cur->next != nullptr) MinHeap.push(cur->next);

    while (!MinHeap.empty()) {

        ListNode* nextnode = MinHeap.top();
        MinHeap.pop();

        cur->next = nextnode;
        cur = nextnode;

        if (nextnode->next != nullptr) {

            MinHeap.push(nextnode->next);

        }

    }

    return head;

}

//寻找最大线段重合数量
vector <int> heap(1e5 + 5, 0);
int siz = 0;

void swap(int i, int j) {

    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;

}


void add(int v) {

    int i = siz;
    heap[siz++] = v;

    while (heap[i] < heap[(i - 1) / 2]) {

        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;

    }

}

void pop() {

    swap(0, siz - 1);
    siz--;

    int le = 1, loc = 0;

    while (le < siz) {

        int min_child = le + 1 < siz && heap[le + 1] < heap[le] ? le + 1 : le;
        
        if (heap[min_child] > heap[loc]) break;

        swap(loc, min_child);

        loc = min_child;
        le = min_child * 2 + 1;

    } 

}

//将区间分成最少组数

int solve(vector <vector <int> >& arr) {

    sort(arr.begin(), arr.end() + arr.size(), [](vector <int>& a, vector <int>& b) {

        return a[0] < b[0];

    });

    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {

        bool Aflag = false;

        while (siz > 0 && heap[0] < arr[i][0]) {

            pop();
            Aflag = true;

        }
        
        if (!Aflag) ans++;
        
        add(arr[i][1]);

    }

    return ans;

}