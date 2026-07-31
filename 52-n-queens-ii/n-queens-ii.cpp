class Solution {
public:


    vector<vector<char>> grid;
    vector<vector<string>> ans;
    bool check(int i, int j, int n) {

        for (int k = 0; k < i; k++) {
            if (grid[k][j] == 'Q')
                return 0;
        }

        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
            if (grid[row][col] == 'Q')
                return 0;
        }
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++) {
            if (grid[row][col] == 'Q')
                return 0;
        }
        return 1;
    }
    void f(int row, int n) {
        if (row == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string t(grid[i].begin(), grid[i].end());
                temp.push_back(t);
            }
            ans.push_back(temp);

            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(row, i, n)) {
                grid[row][i] = 'Q';

                f(row + 1, n);
                grid[row][i] = '.';
            }
        }
        return;
    }
   int solveNQueens(int n) {
        grid.resize(n, vector<char>(n, '.'));
        ans.resize(0);
        f(0, n);
        return ans.size();
    }

    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};