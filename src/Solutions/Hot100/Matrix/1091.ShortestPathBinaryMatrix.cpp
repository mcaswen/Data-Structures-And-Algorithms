#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;


/// A*算法复刻
/// 启发函数hx：八方向用切比雪夫距离，公式max(abs(x - tx), abs(y - ty))，适用于斜走和直走代价相同,g(x)为已走过路径的总代价，fx = gx + hx，
/// 核心算法：
/// 初始化：node定义xy, f(总代价), g（从起点走到当前点的最小代价），开启列表按f排序的最小堆
/// 父节点列表，g列表全部初始化为int最大值，起点g值初始化为0，计算起点f值，加入开启列表
/// 更新流程：从开启列表中拿出f最小的顶点，遇到当前gScore比gScore列表记录的更大，说明顶点已有更优路径，就跳过
/// 然后对于顶点在八方向上的每一个邻居：如果发现当前计算出gScore比gScore更小，就说明当前路径代价更小更优
/// 那么就更新邻居的f，父节点，g值，g值列表，父节点列表，然后加入开启列表
/// 停止条件：当终点作为开启列表中 f 最小的节点被弹出时停止

/// A*算法是一种用来搜索从起点到目标点的最短路径的算法。
/// 其核心是，它会保存所有已经发现，可能成为最短路径中一个节点，等待拓展的所有节点列表，每次取预估距离最小的点出来，并拓展它的邻居，直到顶点为终点
/// 如果某个邻居节点计算后走过的路径代价小于已经记录的路径代价，那么它就可能成为最优路径上的下一个点，把它加入开启列表
/// 对于代价计算，其核心是fx = gx + hx，其中fx是总代价，也是开启列表的排序依据，gx是起点沿路径走到该点的代价，hx是启发函数计算出的该点走到终点的预估代价
/// 由于启发函数总是保证其预估代价小于等于实际代价，所以任何可能解都不会估算得比实际路径更贵，因此终点以最小 f 弹出时，不可能还存在未搜索完的更短路径

class Solution {
public:

    int dx[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {-1, 1, 1, -1, 0, 0, -1, 1};

    struct Point
        {
            int x = 0;
            int y = 0;
            int f = 0;
            int g = 0;

            bool operator==(const Point& other) const
            {
                return other.x == x && other.y == y;
            }
        };

    struct Compare
    {
        bool operator()(const Point& a, const Point& b) const
        {
            return a.f > b.f;
        }
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {

        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        priority_queue<Point, vector<Point>, Compare> openList;
        vector<vector<pair<int, int>>> parent(
            n,
            vector<pair<int, int>>(n, make_pair(-1, -1))
        );
        vector<vector<int>> gScore(
            n, 
            vector<int>(n, INT_MAX)
        );

        Point end;
        end.x = n - 1;
        end.y = n - 1;

        Point start;
        start.x = 0;
        start.y = 0;
        start.g = 0;
        start.f = f(start, end);
        gScore[start.x][start.y] = start.g;

        openList.push(start);

        while (!openList.empty())
        {
            Point cur = openList.top();
            openList.pop();

            if (cur.g > gScore[cur.x][cur.y])
            {
                continue;
            }

            if (cur == end) 
            {
                return backTrack(start, end, parent).size();
            }

            for (int k = 0; k < 8; k++)
            {
                Point next;
                next.x = cur.x + dx[k];
                next.y = cur.y + dy[k];

                if (!isValid(grid, next, grid.size())) continue;

                int nextGScore = cur.g + 1;

                if (nextGScore < gScore[next.x][next.y])
                {
                    gScore[next.x][next.y] = nextGScore;
                    parent[next.x][next.y] = make_pair(cur.x, cur.y);
                    next.g = nextGScore;
                    next.f = f(next, end);

                    openList.push(next);
                }
            }
        }

        return -1;
    }

    int h(const Point& p, const Point& end)
    {
        return max(abs(p.x - end.x), abs(p.y - end.y));
    }

    int g(const Point& p)
    {
        return p.g;
    }

    int f(const Point& p, const Point& end)
    {
        return h(p, end) + g(p);
    }

    vector<Point> backTrack(Point start, Point end, const vector<vector<pair<int, int>>>& parent)
    {
        vector<Point> path;
        Point cur = end;

        while(!(cur == start))
        {
            path.push_back(cur);

            auto [parentX, parentY] = parent[cur.x][cur.y];

            cur.x = parentX;
            cur.y = parentY;
        }

        path.push_back(start);
        reverse(path.begin(), path.end());

        return path;
    }

    bool isValid(const vector<vector<int>>& grid, Point p, int n)
    {
        return p.x >= 0 && p.y >= 0 && p.x < n && p.y < n && grid[p.x][p.y] == 0;
    }
};