class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        ans.assign(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;
        for (auto it : sources) {
            q.push({it[0], it[1], it[2]});
            // ans[it[0]][it[1]]=it[2];
        }
        set<pair<int,int>>st;
        while (!q.empty()) {
            int s = q.size();
             st.clear();
            for (int k = 0; k < s; k++) {
                auto [r, c, v] = q.front();
                q.pop();
                if (ans[r][c] >= v)
                    continue;


                  
                if (ans[r][c] == 0) {
                    ans[r][c] = v;
                    if (r + 1 < n && ans[r + 1][c] == 0)
                        q.push({r + 1, c, v});
                    if (r - 1 >= 0 && ans[r - 1][c] == 0)
                        q.push({r - 1, c, v});
                    if (c + 1 < m && ans[r][c + 1] == 0)
                        q.push({r, c + 1, v});
                    if (c - 1 >= 0 && ans[r][c - 1] == 0)
                        q.push({r, c - 1, v});
                    st.insert({r,c});
                }
               else if(st.find({r,c}) != st.end()) {
                    
                   ans[r][c] = v;
                    if (r + 1 < n && ans[r + 1][c] == 0)
                        q.push({r + 1, c, v});
                    if (r - 1 >= 0 && ans[r - 1][c] == 0)
                        q.push({r - 1, c, v});
                    if (c + 1 < m && ans[r][c + 1] == 0)
                        q.push({r, c + 1, v});
                    if (c - 1 >= 0 && ans[r][c - 1] == 0)
                        q.push({r, c - 1, v});
                }
            }
        }

        return ans;
    }
};