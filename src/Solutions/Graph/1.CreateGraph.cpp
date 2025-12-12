#include <utility>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;


class CreateGraph
{
    const static int MAXN = 11; // 点的最大数量

    const static int MAXM = 21; // 边的最大数量，链式前向星用，无向图要 *2

    int graph1[MAXN][MAXN]; // 邻接矩阵建图

    vector< vector<int> > graph2; // 邻接表建无权图
    vector< vector< pair<int, int> > > graph3; // 邻接表建带权图

    // 链式前向星建图
    int Head[MAXN] = {0};
    int Next[MAXM] = {0};
    int To[MAXM] = {0};
    int cnt = 1;
    int Weight[MAXM] = {0}; // 带权时需要


    // 初始化邻接矩阵
    void Initialize1()
    {
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                graph1[i][j] = 0;
    }

    // 初始化邻接表
    void Initialize2()
    {
        for (int i = 0; i < MAXN + 1; ++i)
        {
            auto list = vector<int>();
            graph2.push_back((list));
        }
    }

    // 邻接矩阵有向带权图添边
    void Add1Weighted(tuple<int, int, int> edge)
    {
        auto [origin, target, weight] = edge;
        graph1[origin][target] = weight;
    }

    // 邻接矩阵无向无权图添边
    void Build1Undirected(pair<int, int> edge)
    {
        auto [origin, target] = edge;
        
        graph1[origin][target] = 1;
        graph1[target][origin] = 1; // 同时设置对称反向
    }

    // 邻接表有向带权图添边
    void Add2Weighted(tuple<int, int, int> edge)
    {
        auto [origin, target, weight] = edge;
        graph3[origin].push_back(make_pair(target, weight));
    }

    // 邻接表无向无权图添边
    void Build2Undirected(pair<int, int> edge)
    {
        auto [origin, target] = edge;
        
        graph2[origin].push_back(target);
        graph2[target].push_back(origin); // 同时设置对称反向
    }

    // 链式前向星添带权边
    void Build3Weighted(tuple<int, int, int> edge)
    {
        auto [origin, target, weight] = edge;
        int last = Head[origin];

        Head[origin] = cnt;
        Next[cnt] = last;
        To[cnt] = target;
        Weight[cnt] = weight;
    }


    void PrintGraph1()
    {
        for (auto& row: graph1)
        {    
            for (auto num: row)
                cout << num << " ";
            cout << endl;
        }
    }

    void PrintGraph2()
    {
        int numOfEdges = 0;   
        for (int i = 0; i < MAXN; i++)
        {   
            for (auto& to: graph2[i])
            {
                numOfEdges++;
                cout << "边 " << numOfEdges << " : " << "(" << i << ", " << to << ")\n";
            }
            
        }
    }

    void PrintGraph3()
    {
        int cnt = 0;
        for (int i = 0; i < MAXN; i++)
        {
            int last = Head[i];
            while (last != 0)
            {
                cnt++;
                cout << "边 " << cnt << ": (" << i << ", " << To[last] << "), weight: " << Weight[last] << "\n";
                last = Next[last]; 
            }
        }
    }
};