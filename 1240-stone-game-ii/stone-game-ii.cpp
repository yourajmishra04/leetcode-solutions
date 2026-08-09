class Solution {
public:
    int ans = 0;
     int dp[101][101][2];
    int solve(vector<int>& piles, int idx, int m, bool flg) {

        if (idx >= piles.size()) {

            return 0;
        }
         if (dp[idx][m][flg] != -1)
            return dp[idx][m][flg];
  int fans,temp;
        if (flg == 1) {

             fans = 0, temp = 0;
            for (int i = idx; i < idx + 2 * m && i < piles.size(); i++) {
                temp += piles[i];
                fans = max(fans,
                           temp + solve(piles, i + 1, max(m, i-idx  + 1), 0));
            }

        } else {

             fans = INT_MAX, temp = 0;
            for (int i = idx; i < idx + 2 * m && i < piles.size(); i++) {
                temp += piles[i];
                fans = min(fans, solve(piles, i + 1, max(m, i-idx  + 1), 1));
            }
        }
         return dp[idx][m][flg] = fans;
    }
    int stoneGameII(vector<int>& piles) {  memset(dp, -1, sizeof(dp)); return solve(piles, 0, 1, 1); }
};