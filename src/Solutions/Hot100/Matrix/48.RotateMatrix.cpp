#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/// 处理旋转矩阵，想到两种思路，一种是从i, j入手，一种是转换成一维之后从mod入手
/// 一开始想了一维和余数mod，结果没有什么好发现
/// 换了 i, j 考虑之后观察后发现，旋转90度，本质上是先把 i j 对调，然后用 (n - 1) - j
/// 例如(0, 1)位置旋转，先对调到(1, 0)，再用 n - 1 - 0，得到(1, n - 1)
/// 从0, 0开始处理，处理方式为不断交换直到回到原点，再处理1, 0，以此类推，直到(n - 1, 0)处理完第一行后最外围(第0围)处理完毕
/// 再i + 1, j + 1处理(1, 1)，即第1围，以此类推，直到(1, n - 2)
/// 中止条件为 i == j > (n - 1) / 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for (int i = 0; i < n / 2;++i)
        {
            for (int iniRow = i, iniCol = i; iniCol < n - 1 - i; ++iniCol)
            {   
                int curRow = iniRow;
                int curCol = iniCol;

                int last = matrix[curRow][curCol];

                do
                {
                    // 先拿到要交换过去的元素
                    int cur = last;

                    // 拿到目标位置
                    int temp = curRow;
                    curRow = curCol;
                    curCol = temp;

                    curCol = n - 1 - curCol;

                    // 保存目标位置上的元素，也就是下一次要交换的元素
                    last = matrix[curRow][curCol];
                    // 目标位置赋值本次要交换的元素
                    matrix[curRow][curCol] = cur;

                } while (curRow != iniRow || curCol != iniCol);
            }
        }
    }
};