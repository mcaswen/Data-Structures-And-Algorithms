//leetcode 130
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector <vector <char> >& board, int i, int j, int n, int m) {
    
    if (i < 0 || i == n || j < 0 || j == m || board[i][j] != 'O') {

        return;
            
    }
    
    board[i][j] = 'B';

    for (int k = 0; k < 4; k++) {

        dfs(board, i + dx[k], j + dy[k], n, m);

    }
    
}

void solve(vector<vector<char>>& board) {
    
    int n = board.size();
    int m = board[0].size();

    for (int j = 0; j < m; j++) {

        if (board[0][j] == 'O') dfs(board, 0, j, n, m);
        if (board[n-1][j] == 'O') dfs(board, n-1, j, n, m);

    }

    for (int i = 0; i < n; i++) {

        if (board[i][0] == 'O') dfs(board, i, 0, n, m);
        if (board[i][m-1] == 'O') dfs(board, i, m-1, n, m);

    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            
            if (board[i][j] == 'O')
                board[i][j] = 'X';

            else if (board[i][j] == 'B')
                board[i][j] = 'O';

        }

}