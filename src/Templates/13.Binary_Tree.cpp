#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

#define maxd 20

vector <int> s(1 << maxd + 5, 0);

signed simulate() {

    int I, D;

    while (cin >> D >> I) {

        fill(s.begin(), s.end(), 0);

        int k, n = (1 << D) - 1;

        //暴力模拟
        for (int i = 0; i < I; i++) {

            k = 1;

            while (1) {

                s[k] = !s[k];
                k = s[k] ? s[k] * 2 : s[k] * 2 + 1;

                if (k > n) break;

            }

        }

        cout << k / 2 << endl;

        //利用奇偶性
        for (int i = 0; i < D - 1; i++) {

            if (I % 2) {

                k *= 2;
                I = (I + 1) / 2;

            } else {

                k = k * 2 + 1;
                I /= 2;

            }

        }

        cout << k << endl;

    }

}

//二叉树的模拟创建和遍历

bool failed;

struct Node {

    bool have_valued;
    int v;

    Node *left, *right;

    Node(): have_valued(false), left(NULL), right(NULL) {}

};

Node* root;

Node* newnode() {

    return new Node();

}

void addnode(int v, string ch, size_t i) {

    int n = ch.size();
    Node* u = root;

    for (; i < n; i++) {

        if (s[i] == 'L') {
            if (u->left == NULL) 
                u->left = newnode();

            u = u->left;

        } 
        else if (s[i] == 'R') {
            if (u->right == NULL)
                u->right = newnode();

            u = u->right;

        }

        if (u->have_valued) 
            failed = true;

        u->v = v;
        u->have_valued = true;

    }

}

vector <int> ans;

bool bfs(vector <int>& ans) {

    deque < Node* > q;

    ans.clear();
    q.push_back(root);

    while (!q.empty()) {
        
        Node* u = q.front();
        q.pop_back();

        if (!u->have_valued) return false;
        ans.push_back(u->v);

        if (u->right != NULL) q.push_back(u->right);
        if (u->left != NULL) q.push_back(u->left);
    
    }

    return true;

}

//先序遍历
void pre_order_traversal(Node* node) {

    if (node == NULL) return;

    cout << node->v << " ";

    pre_order_traversal(node->left);
    pre_order_traversal(node->right);

}

//中序遍历
void in_order_traversal(Node* node) {

    if (node == NULL) return;

    in_order_traversal(node->left);

    cout << node->v << " ";

    in_order_traversal(node->right);

}

//后序遍历
void post_order_traversal(Node* node) {

    if (node == NULL) return;

    post_order_traversal(node->left);
    post_order_traversal(node->right);
    
    cout << node->v << " ";

}

string ch;

bool read_input() {

    failed = false;
    root = newnode();

    while (1) {

        if (!(cin >> ch)) return false;
        if (ch == "()") break;
        
        int v;
        
        sscanf(&ch[1], "%d", &v);
        addnode(v,ch, ch.find(',') + 1);

    }

    return true;

}

//层序遍历
struct TreeNode {
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

vector< vector<int> > level_bfs1(TreeNode* root) {

    deque < TreeNode* > dq;
    vector< vector<int> > ans;
    map <TreeNode*, int> mp;
    if (!root) return ans;

    dq.push_back(root); 
    mp[root] = 0;

    while (!dq.empty()) {

        TreeNode* cur = dq.front();
        dq.pop_front();

        int level = mp[cur];

        if (ans.size() == level) {

            vector <int> cur_list;
            ans.push_back(cur_list);

        }

        ans[level].push_back(cur->val);

        if (cur->left != NULL) {
        
            mp[cur->left] = level + 1;
            dq.push_back(cur->left);
        
        }
        
        if (cur->right != NULL) {
            
            mp[cur->right] = level + 1;
            dq.push_back(cur->right);
        
        }
    
    }   

    return ans;

}

//优化版层序遍历
vector <vector <int> > level_bfs2(TreeNode* root) {

    vector <vector <int> > ans;
    deque <TreeNode*> dq;
    //求特殊宽度用到的双端队列
    //deque <int> idq;
    //int maxx = -1;

    if (!root) return ans;
    dq.push_back(root);

    //idq.push_back(1);

    //锯齿形遍历用到的“全局”变量
    bool reverse = 0;
    
    while (!dq.empty()) {

        int n = dq.size();
        vector <int> sub_list;

        //锯齿形遍历
        //if (!reverse) {for (auto it = dq.begin(); it != dq.end(); it++) sub_list.push_back((*it)->val); reverse = 1;}
        //else {for (auto it = dq.rbegin(); it != dq.rend(); it++) sub_list.push_back((*it)->val); reverse = 0;}

        //计算特殊宽度最大值
        //maxx = max(maxx, idq.back() - idq.front() + 1);

        while (n--) {

            TreeNode* cur = dq.front();
            dq.pop_front();

            //int cur_id = idq.front();
            //idq.pop_front();

            //使用锯齿形遍历时删除这行
            sub_list.push_back(cur->val);

            if (cur->left) dq.push_back(cur->left); //idq.push_back(cur_id * 2);
            if (cur->right) dq.push_back(cur->right);//idq.push_back(cur_id * 2 + 1);

        }

        ans.push_back(sub_list);

    }

    return ans;

}

//找最大深度

int max_depth(TreeNode* root) {

    if (!root) return 0;

    return 1 + max(max_depth(root->left), max_depth(root->right));

}

//找最小深度
int min_depth(TreeNode* root) {

    int depth = 0;

    if (!root) return 0;

    deque <TreeNode*> dq;

    depth = 0;
    dq.push_back(root);

    while (!dq.empty()) {

        int n = dq.size();
        depth++;
        
        for (int i = 0; i < n; i++) {

            TreeNode* cur = dq.front();
            dq.pop_front();

            if (!cur->left && !cur->right) return depth;

            if (cur->left) dq.push_back(cur->left);
            if (cur->right) dq.push_back(cur->right);
        
        }

    }

    return '?';

}

//序列化先序二叉树

void f2(TreeNode* root, ostringstream& oss) {

    if (!root) oss << "# ";

    else {
        
        oss << root->val << " ";

        f2(root->left, oss);
        f2(root->right, oss);
    
    }
}

string serialize(TreeNode* root) {

    ostringstream oss;

    f2(root, oss);

    return oss.str();

}

//反序列化先序二叉树

vector <string> split1(string s, char del) {

    string tok;
    istringstream tokstream(s);
    vector <string> toks;

    while (getline(tokstream, tok, del)) {
    
        toks.push_back(tok);

    }

    return toks;

}

TreeNode* g(const vector <string>& ss, int& cnt) {
    
    if (ss[cnt] == "#") {cnt++; return NULL;}

    TreeNode* root = new TreeNode(stoi(ss[cnt++]));

    root->left = g(ss, cnt);
    root->right = g(ss, cnt);

    return root;

}


TreeNode* deserialize(string s) {

    vector <string> ss = split1(s, ' ');

    int cnt = 0;

    TreeNode* root = g(ss, cnt);

    return root;

}

//层序二叉树序列化与反序列化

string f3(TreeNode* root, ostringstream& ss) {

    if (!root) {ss << "# "; return ss.str();}

    deque <TreeNode*> dq;
    ss << root->val << " ";
    dq.push_back(root);

    while (!dq.empty()) {

        TreeNode* cur = dq.front();
        dq.pop_front();

        if (cur->left) {

            ss << cur->left->val << " ";
            dq.push_back(cur->left);

        } else ss << "# ";

        if (cur->right) {

            ss << cur->right->val << " ";
            dq.push_back(cur->right);

        } else ss << "# ";

    }

    return ss.str();

}

string serialize2(TreeNode* root) {

    ostringstream ss;

    return f3(root, ss);

}

vector <string> split(string s, char del) {

    vector <string> v;
    string buf;
    istringstream ss(s);
    
    while (getline(ss, buf, del)) {
        
        if (!buf.empty())
            v.push_back(buf);

    }

    return v;

}

TreeNode* g3(const vector <string>& v) {

    int cnt = 0;
    if (v[cnt] == "#") return NULL;   

    TreeNode* root = new TreeNode(stoi(v[cnt++]));

    deque <TreeNode*> dq;
    dq.push_back(root);

    while (!dq.empty()) {

        TreeNode* cur = dq.front();
        dq.pop_front();

        if (v[cnt] == "#" ) cur->left = NULL;
        
        else {
            
            cur->left = new TreeNode(stoi(v[cnt])); 
            dq.push_back(cur->left);
        
        }

        cnt++;

        if (v[cnt] == "#") cur->right = NULL;

        else {

            cur->right = new TreeNode(stoi(v[cnt]));
            dq.push_back(cur->right);

        }

        cnt++;
    
    }
    
    return root;

}

TreeNode* deserialize2(string s) {

    vector <string> v = split(s, ' ');

    return g3(v);

}

//利用先序遍历和中序遍历数组重建二叉树

TreeNode* BuildHelper(const vector <int>& pre, int l1, int r1,
                     const vector <int> & in, int l2, int r2,
                      unordered_map <int, int>& inmp) {


    if (l1 > r1) return NULL;

    TreeNode* node = new TreeNode(pre[l1]);

    if (l1 == r1) return node;

    int k = inmp[pre[l1]];

    //左节点递归中r1应等于l1 + left_nodes = l1 + k - l2.(在中序遍历中左子树节点范围为l2 ~ k-1, 共k - l2 个节点)
    //右节点递归中r1 = 左节点r1 + 1，若左节点递归位置错误则右节点递归位置自然错误

    node->left = BuildHelper(pre, l1 + 1, l1 + (k - l2), in, l2, k - 1, inmp);
    node->right = BuildHelper(pre, (l1 + (k - l2)) + 1, r1, in, k + 1, r2, inmp);

    return node;

}

TreeNode* BuildTree(vector <int> pre, vector <int> in) {

    unordered_map <int, int> inmp;

    for (int i = 0; i < in.size(); i++) {

        inmp[in[i]] = i;

    }

    return BuildHelper(pre, 0, pre.size() - 1, in, 0, in.size() - 1, inmp);

}

//检验完全二叉树
bool CheckTree(TreeNode* root) {

    if (!root) return true;

    deque <TreeNode*> dq;
    dq.push_back(root);
    bool find = false;

    while (!dq.empty()) {

        TreeNode* cur = dq.front();
        dq.pop_front();

        if (!cur->left && cur->right) return false;
        
        //只要find = true，那么当且仅当之后所有节点都是叶子结点的情况下才是完全二叉树，只要有一个节点不是叶子结点，那么树都不是完全二叉树，所以之后的节点只要有子节点就不是完全二叉树。
        //find在循环最后更新，所以只会检查之后的节点

        if (find && (cur->left || cur->right)) return false;

        if (cur->left) dq.push_back(cur->left);
        if (cur->right) dq.push_back(cur->right);

        if (!cur->left || !cur->right) find = true;

    }

    return true;

}

//计算完全二叉树的节点数量

int max_dep(TreeNode* root, int level) {

    while (root) {

        level++;
        root = root->left;

    }

    return level - 1;
}

int f(TreeNode* root, int level, int h) {

    if (h == level) return 1;

    if (max_dep(root->right, level +1 ) == h) {

        return (1 << (h - level)) + f(root->right, level + 1 , h);

    } else {
                //完全二叉树的深度只能是h或h-1
        return (1 << (h - level - 1)) + f(root->left, level + 1, h);

    }

}

int cal(TreeNode* root) {

    if (!root) return 0;

    return f(root, 1, max_dep(root, 1));

}