class Solution {
public:
    set<int> st;
    bool solve(vector<int>& v, int start) {
        int n = v.size();
        queue<int> q;
        vector<bool> vis(n, 0);
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (st.find(idx) != st.end()) {
                return 1;
            }

            int i = idx + v[idx];
            if (i < n && !vis[i]) {
                q.push(i);
                vis[i] = 1;
            }

            i = idx - v[idx];
            if (i >= 0 && !vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
        return 0;
    }
    bool canReach(vector<int>& arr, int start) {
        st.clear();

        for (int i = 0; i < arr.size(); i++)
            if (arr[i] == 0)
                st.insert(i);

        return solve(arr, start);
    }
};