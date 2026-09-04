class Solution {
public:

    pair<int, int> dfs(int parent, int node, vector<vector<int>>& mat) {

        pair<int, int> best = {0, node};

        for (int child : mat[node]) {

            if (child == parent)
                continue;

            auto temp = dfs(node, child, mat);

            if (temp.first + 1 > best.first) {
                best = {temp.first + 1, temp.second};
            }
        }

        return best;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> mat(n);

        for (auto &e : edges) {
            mat[e[0]].push_back(e[1]);
            mat[e[1]].push_back(e[0]);
        }

        if (n == 1)
            return {0};

        int A = dfs(-1, 0, mat).second;

        
        int B = dfs(-1, A, mat).second;

       
        vector<int> parent(n, -1);

        function<bool(int, int)> getPath = [&](int node, int par) {

            if (node == B)
                return true;

            for (int child : mat[node]) {

                if (child == par)
                    continue;

                parent[child] = node;

                if (getPath(child, node))
                    return true;
            }

            return false;
        };

        getPath(A, -1);

        vector<int> path;

        int cur = B;

        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        reverse(path.begin(), path.end());

        int sz = path.size();

        if (sz % 2)
            return {path[sz / 2]};

        return {
            path[sz / 2 - 1],
            path[sz / 2]
        };
    }
};