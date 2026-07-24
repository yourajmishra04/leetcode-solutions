class Solution {
public:
    bool flg;
    int n, tot;
    bool solve(vector<int>& mat, int i, int a, int b, int c, int d) {
        if(a>tot || b>tot || c>tot || d>tot) return 0;
        if (i == n) {
            if (a == b && b == c && c == d)
                return 1;

            else
                return 0;
        }
        bool ans = solve(mat, i + 1, a + mat[i], b, c, d) ||
                   solve(mat, i + 1, a, b + mat[i], c, d) ||
                   solve(mat, i + 1, a, b, c + mat[i], d) ||
                   solve(mat, i + 1, a, b, c, d + mat[i]);

        return ans;
    }
    bool makesquare(vector<int>& mat) {
        sort(mat.rbegin(),mat.rend());
        n = mat.size();
        tot = 0;
        flg = 0;
       int a =0, b =0, c =0, d = 0;
        for (int i = 0; i < n; i++)
            tot += mat[i];
           if (tot % 4 != 0)
    return false;
      tot/=4;
       return solve(mat,0, a,b,c,d);
        return flg;
    }
};