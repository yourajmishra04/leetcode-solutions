class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int>& col) {

        int n = col.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));

       
        for (int j = 0; j < n; j++) {
            if (col[j] == 2) {
                ans[0][j] = 1;
                ans[1][j] = 1;
                upper--;
                lower--;
                col[j] = 0;
            }
        }

        if (upper < 0 || lower < 0)
            return {};

        
        for (int j = 0; j < n; j++) {
            if (col[j] == 1) {

                if (upper > 0) {
                    ans[0][j] = 1;
                    upper--;
                } else if (lower > 0) {
                    ans[1][j] = 1;
                    lower--;
                } else {
                    return {};
                }

                col[j] = 0;
            }
        }

        if (upper != 0 || lower != 0)
            return {};

        return ans;
    }
};